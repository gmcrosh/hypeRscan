context("test-count")
data("awtew")

test_that("hs_str_count is the count of patterns", {
  expect_equal(hs_str_count(c("a","b"),"a"), c(1,0))
  expect_equal(sum(hs_str_count(awtew, "[L|l]ord")), 240)
})

test_that("hs_str_count of factor is the count of patterns", {
  expect_equal(hs_str_count(factor(c("a","b")),"a"), c(1,0))
})

test_that("hs_str_count of missing is a missing", {
  expect_equal(hs_str_count(c(NA),"a"), as.integer(c(NA)))
  expect_equal(hs_str_count(c(NA,"a"),"a"), c(NA,1))
})