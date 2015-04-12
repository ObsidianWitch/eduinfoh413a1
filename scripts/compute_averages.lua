#!/usr/bin/lua

experiments_dir = "../experiments"
out_dir = "../out/experiments"

function retrieveInstances()
    local experiments = io.popen("ls " .. experiments_dir .. "/*")
    local tExperiments = {}
    
    for experiment in experiments:lines() do
        table.insert(tExperiments, experiment)
    end
    
    return tExperiments
end

function extractWriteData(experiment, averagesFile)
    local experimentFile = io.open(experiment, "r")
    local averageDelta = 0;
    local timeSum = 0;
    local timeAverage = 0;
    
    for line in experimentFile:lines() do
        local delta, time = line:match("N-.+50 %d+ %d+ (%d+.%d+) (%d+.%d+)")
        averageDelta = averageDelta + delta
        timeSum = timeSum + time
    end
    
    averageDelta = averageDelta / 78
    timeAverage = timeSum / 78
    
    averagesFile:write(experiment .. " " .. averageDelta .. " " .. timeSum
        .. " " .. timeAverage .. "\n")
end

-- Main
experiments = retrieveInstances()

os.execute("mkdir -p " .. out_dir)

for k, experiment in pairs(experiments) do
    local averagesFile = io.open(out_dir .. "/averages", "a")
    extractWriteData(experiment, averagesFile)
    averagesFile:close()
end
