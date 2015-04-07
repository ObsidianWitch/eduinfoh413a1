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
    
    local total = 12 * nInstances + 2 * nInstances
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
        
        --print(line)
    end
    
    file:write(instanceName .. " " .. finalScore .. " " .. bestKnownScore
        .. " " .. timeElapsed .. "\n")
    
    return finalScore, bestKnownScore, timeElapsed
end

function computeIIInstance(initialization, pivotingRule, neighbourhood)
    for k, instance in pairs(instances) do
        scriptProgress()
        -- FIXME os.execute("../out/lop"
        print("../out/lop"
            .. " -i " .. initialization
            .. " -p " .. pivotingRule
            .. " -n " .. neighbourhood
            .. " -f " .. instance
        )
        print()
    end
end

function computeVNDInstance(neighbourhood)
    for k, instance in pairs(instances) do
        scriptProgress()
        -- FIXME os.execute("../out/vnd"
        print("../out/vnd"
            .. " -n " .. neighbourhood
            .. " -f " .. instance
        )
        print()
    end
end

for k1, initialization in pairs(ii_initialization_opts) do
    for k2, pivotingRule in pairs(ii_pivoting_opts) do
        for k3, neighbourhood in pairs(ii_neighbourhood_opts) do
            computeIIInstance(initialization, pivotingRule, neighbourhood)
        end
    end
end

for k1, neighbourhood in pairs(vnd_neighbourhood_opts) do
    computeVNDInstance(neighbourhood)
end

---[[FIXME BEGIN TEST ONLY
local instanceName = "../instances/N-t65f11xx_150"
local testInstance = io.popen("../out/lop -i random -p first -n transpose -f "
    .. instanceName)

local file = io.open("test", "a")
local finalScore, bestKnownScore, timeElapsed = extractWriteData(testInstance,
    instanceName, file)
file:close()

print(finalScore)
print(bestKnownScore)
print(timeElapsed)
-- FIXME END TEST ONLY
--]]
 
