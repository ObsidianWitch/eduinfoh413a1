#!/usr/bin/lua

ii_initialization_opts = { "cw", "random" }
ii_pivoting_opts = { "first", "best" }
ii_neighbourhood_opts = { "transpose", "exchange", "insertion" }
vnd_neighbourhood_opts = { "tei", "tie" }

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
    
    local total = 14 * nInstances
    print("[" .. scriptProgression .. "/" .. total .. "]")
end

function extractWriteData(instance, instanceName, file)
    local finalScore, bestKnownScore, timeElapsed
    
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
    
    file:write(instanceName .. " " .. finalScore .. " " .. bestKnownScore
        .. " " .. timeElapsed .. "\n")
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

-- Main
os.execute("mkdir -p ../out/summary/")

for k1, initialization in pairs(ii_initialization_opts) do
    for k2, pivotingRule in pairs(ii_pivoting_opts) do
        for k3, neighbourhood in pairs(ii_neighbourhood_opts) do
            local fileName = "../out/summary/ii_"
                .. initialization .. "_"
                .. pivotingRule .. "_"
                .. neighbourhood
            local file = io.open(fileName, "a")
            
            computeIIInstance(file, initialization, pivotingRule, neighbourhood)
            
            file:close()
        end
    end
end

for k1, neighbourhood in pairs(vnd_neighbourhood_opts) do
    local fileName = "../out/summary/vnd_"
        .. neighbourhood
    local file = io.open(fileName, "a")
    
    computeVNDInstance(file, neighbourhood)
    
    file:close()
end
