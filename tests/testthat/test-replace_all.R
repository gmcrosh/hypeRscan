context("test-replace_all")

test_that("hs_str_replace in the presence of a pattern", {
  expect_equivalent(hs_str_replace_all(c("abc","aabc"),"bc","df"), 
                    c("adf","aadf"))
  expect_equivalent(hs_str_replace_all(c("bcbc","aabc"),"bc","df"), 
                    c("dfdf","aadf"))
})

test_that("hs_str_replace works for NA", {
  expect_equivalent(hs_str_replace_all(c(NA),"a","b"), as.character(c(NA)))
  expect_equivalent(hs_str_replace_all(c("a","aa", NA),"a","b"), as.character(c("b","bb",NA)))
})