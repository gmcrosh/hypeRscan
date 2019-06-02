context("test-replace")

test_that("hs_str_replace in the presence of a pattern", {
  expect_equivalent(hs_str_replace(c("abc","aabc"),"bc","df"), 
                    c("adf","aadf"))
  expect_equivalent(hs_str_replace(c("bcbc","aabc"),"bc","df"), 
                    c("dfbc","aadf"))
})

test_that("hs_str_replace works for NA", {
  expect_equivalent(hs_str_replace(c(NA),"a","b"), as.character(c(NA)))
  expect_equivalent(hs_str_replace(c("a", NA),"a","b"), as.character(c("b",NA)))
})