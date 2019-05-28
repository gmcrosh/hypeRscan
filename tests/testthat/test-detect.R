context("test-detect")
data("awtew")

test_that("hs_str_detect is the presence of a pattern", {
  expect_equal(hs_str_detect(c("a","b"),"a"), c(T,F))
  expect_equal(sum(hs_str_detect(awtew, "[L|l]ord")), 240)
})

test_that("hs_str_detect of factors works", {
  expect_equal(hs_str_detect(factor(c("a","b")),"a"), c(T,F))
})
