context("test-locate_all")

test_that("hs_str_locate_all in the presence of a pattern", {
  expect_equivalent(hs_str_locate_all(c("bcbc","aabc"),"bc"), 
                    list(matrix(data=c(0,2,2,4),2,2), matrix(data=c(2,4),1,2)))
})

test_that("hs_str_locate_all works for NA", {
  expect_equivalent(hs_str_locate_all(c(NA),"a"), 
                    list(matrix(data=as.integer(c()),0,2)))
  expect_equivalent(hs_str_locate_all(c("ZZZ"),"a"), 
                    list(matrix(data=as.integer(c()),0,2)))
  expect_equivalent(hs_str_locate_all(c("ZZZ","a"),"a"), 
                    list(matrix(data=as.integer(c()),0,2), matrix(c(0,1),1,2)))
})