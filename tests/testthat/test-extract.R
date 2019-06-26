context("test-extract")

test_that("hs_str_extract in the presence of a pattern", {
  expect_equivalent(hs_str_extract(c("abc","bc"),"[ab]"), 
                    c("a","b"))
  expect_equivalent(hs_str_extract(c("bcbc","aabc"),"[bc]"), 
                    c("b","b"))
})

test_that("hs_str_extract works for NA", {
  expect_equivalent(hs_str_extract(c(NA),"a"), as.character(c(NA)))
  expect_equivalent(hs_str_extract(c("a", NA),"a"), as.character(c("a",NA)))
})