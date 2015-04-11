#!/usr/bin/lua

function retrieveInstances()
    local instances = io.popen('ls ../instances/N-*')
    local tInstances = {}
    local nInstances = 0
    
    for instance in instances:lines() do
        nInstances = nInstances + 1;
        table.insert(tInstances, instance)
    end
    
    return tInstances, nInstances
end
instances, nInstances = retrieveInstances()

scriptProgression = 0
function scriptProgress()
    scriptProgression = scriptProgression + 1
    
    local total = nInstances
    print("[" .. scriptProgression .. "/" .. total .. "]")
end

function extractWriteData(instance, instanceName, file)
    local finalScore, bestKnownScore, delta, timeElapsed
    
    for line in instance:lines() do
        if finalScore == nil then
            finalScore = line:match("final solution %(score: (%d+)")
        end
        
        if bestKnownScore == nil then
            bestKnownScore = line:match("best known score: (%d+)")
        end
        
        if timeElapsed  == nil then
            timeElapsed = line:match("Time elapsed: (%d+.%d+) s")
        end
    end
    
    delta = 100 * (bestKnownScore - finalScore)/bestKnownScore
    
    file:write(instanceName .. " " .. finalScore .. " " .. bestKnownScore
        .. " ".. delta .. " " .. timeElapsed .. "\n")
end

function computeIIInstance(file, initialization, pivotingRule, neighbourhood)
    for k, instanceName in pairs(instances) do
        scriptProgress()
        
        local command = "../out/lop"
            .. " -i " .. initialization
            .. " -p " .. pivotingRule
            .. " -n " .. neighbourhood
            .. " -f " .. instanceName
        print(command .. "\n")
        
        local instance = io.popen(command)
        extractWriteData(instance, instanceName, file)
    end
end

function computeVNDInstance(file, neighbourhood)
    for k, instanceName in pairs(instances) do
        scriptProgress()
        
        local command = "../out/vnd"
            .. " -n " .. neighbourhood
            .. " -f " .. instanceName
        print(command .. "\n")
        
        local instance = io.popen(command)
        extractWriteData(instance, instanceName, file)
    end
end

function computeIIs()
    local initialization = arg[2]
    local pivotingRule = arg[3]
    local neighbourhood = arg[4]

    local fileName = "../out/experiments/ii_"
        .. initialization .. "_"
        .. pivotingRule .. "_"
        .. neighbourhood
    local file = io.open(fileName, "a")
    
    computeIIInstance(file, initialization, pivotingRule, neighbourhood)
    
    file:close()
end

function computeVNDs()
    local neighbourhood = arg[2]
    local fileName = "../out/experiments/vnd_" .. neighbourhood
    local file = io.open(fileName, "a")
        
    computeVNDInstance(file, neighbourhood)
    
    file:close()
end

-- Main
os.execute("mkdir -p ../out/experiments/")

if arg[1] == "lop" then
    computeIIs()
elseif arg[1] == "vnd" then
    computeVNDs()
end
