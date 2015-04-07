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
    
    local total = 12 * nInstances + 2 * nInstances
    print("[" .. scriptProgression .. "/" .. total .. "]")
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

ii_initialization_opts = { "cw", "random" }
ii_pivoting_opts = { "first", "best" }
ii_neighbourhood_opts = { "transpose", "exchange", "insertion" }
vnd_neighbourhood_opts = { "tei", "tie" }

for k1, initialization in pairs(ii_initialization_opts) do
    for k2, pivotingRule in pairs(ii_pivoting_opts) do
        for k3, neighbourhood in pairs(ii_neighbourhood_opts) do
            computeIIInstance(initialization, pivotingRule, neighbourhood)
        end
    end
end
