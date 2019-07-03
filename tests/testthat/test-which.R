context("test-which")
data("awtew")

test_that("hs_str_which in the presence of a pattern", {
  expect_equal(hs_str_which(c("a","b"),"a"), c(1))
})


test_that("hs_str_which works for NA", {
  expect_equal(hs_str_which(c(NA),"a"), as.integer(c()))
  expect_equal(hs_str_which(c(NA,"a"),"a"), c(2))
})