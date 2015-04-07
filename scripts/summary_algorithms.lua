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

ii_initialization_opts = { "cw", "random" }
ii_pivoting_opts = { "first", "best" }
ii_neighbourood_opts = { "transpose", "exchange", "insertion" }
vnd_neighbourood_opts = { "tei", "tie" }

instances, nInstances = retrieveInstances()

for k1, init in pairs(ii_initialization_opts) do
    for k2, piv in pairs(ii_pivoting_opts) do
        for k3, n in pairs(ii_neighbourood_opts) do
            for k4, instance in pairs(instances) do
                os.execute("../out/lop"
                    .. " -i " .. init
                    .. " -p " .. piv
                    .. " -n " .. n
                    .. " -f " .. instance
                )
                print()
            end
        end
    end
end
