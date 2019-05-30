context("test-locate")
data("awtew")

test_that("hs_str_locate in the presence of a pattern", {
  expect_equivalent(hs_str_locate(c("abc","aabc"),"bc"), matrix(data=c(1,2,3,4),2,2))
})

test_that("hs_str_locate works for NA", {
  expect_equivalent(hs_str_locate(c(NA),"a"), matrix(data=as.integer(c(NA,NA)),1,2))
  expect_equivalent(hs_str_locate(c("ZZZ"),"a"), matrix(data=as.integer(c(NA,NA)),1,2))
  expect_equivalent(hs_str_locate(c("ZZZZ","a"),"a"), matrix(data=c(NA,0,NA,1),2,2))
})