library(microbenchmark)
library(hypeRscan)
library(stringr)
library(ggplot2)

awtew <- scan("benchmark/Alls_Well_That_Ends_Well.txt", character(), quote = "")
pattern <- "[Ll]ord"

run_test <- function(func) {
  micro <- microbenchmark(func(awtew, pattern), times = 100)
  avg <- mean(micro$time)
  percentiles <- quantile(micro$time, probs = c(.25,.75))
  return(c(avg, percentiles["25%"], percentiles["75%"]))
}

function_list <- list(
  stringr::str_count,
  hypeRscan::hs_str_count,
  stringr::str_detect,
  hypeRscan::hs_str_detect,
  stringr::str_locate,
  hypeRscan::hs_str_location
)

results <- mapply(run_test, function_list)

benchmark_df <- data.frame(t(results))
names(benchmark_df) <- c('avg', 'percent_25', 'percent_75')
benchmark_df$library <- rep(c("stringr","hypeRscan"),3)
benchmark_df$task <- c(rep("count",2),rep("detect",2),rep("locate",2))

ggplot(benchmark_df, aes(task, avg, fill = library)) +
  geom_col(position = 'dodge') +
  ggtitle("Regular Expression Benchmark")  + ylab("Runtime (µs)")

ggsave("benchmark/benchmark.png",width = 8, height=5)
