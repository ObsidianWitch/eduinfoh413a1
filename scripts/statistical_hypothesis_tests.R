#!/usr/bin/Rscript

# arg[1] should be "ii" or "vnd"
args <- commandArgs(trailingOnly = TRUE)

if (args[1] != "ii" && args[1] != "vnd") {
    stop("Usage: ./script <ii|vnd>")
}

experiments_dir <- "../experiments/"
experiments <- list.files(experiments_dir, args[1])
deltas <- array(0, c(length(experiments), 78))

for (i in 1:length(experiments)) {
    experiment_path <- paste(experiments_dir, experiments[i], sep="")
    deltas[i,] <- read.table(experiment_path)$V4
}

results <- array(0, c(length(experiments), length(experiments), 2))
for (i in 1 : (length(experiments)-1)) {
    for (j in (i+1) : length(experiments)) {
        # Student's t test
        results[i,j,1] <- t.test(deltas[i,], deltas[j,], paired=T)$p.value
        
        # Wilcoxon signed-rank test
        results[i,j,2] <- wilcox.test(deltas[i,], deltas[j,], paired=T)$p.value
    }
}

out.dir = "../out/stats_tests"
out.path = paste(out.dir, args[1], sep="/")
dir.create(out.dir, showWarnings=FALSE)
write.table(results[,,1], paste(out.path, "t", sep="_"))
write.table(results[,,2], paste(out.path, "wilcoxon", sep="_"))
