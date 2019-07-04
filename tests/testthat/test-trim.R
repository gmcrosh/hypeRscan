context("test-trim")

test_that("test left right and both trim", {
  trim_example <- c("  left","right  ", "  both  ")
  expect_equivalent(hs_str_trim(trim_example, "left"), 
                    c("left","right  ", "both  "))
  expect_equivalent(hs_str_trim(trim_example, "right"), 
                    c("  left","right", "  both"))
  expect_equivalent(hs_str_trim(trim_example, "both"), 
                    c("left","right", "both"))
})

test_that("test trim NA handling", {
  expect_equivalent(hs_str_trim(c(NA),"both"), as.character(c(NA)))
  expect_equivalent(hs_str_trim(c("  a  ", NA),"both"), as.character(c("a",NA)))
})