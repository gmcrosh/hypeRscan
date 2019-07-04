#' Trim whitespace
#'
#' @param string Input character vector
#' @param side string, either "both", "left" or "right"
#'
#' @return character vector
#' @export
#'
#' @examples
#' trim <- c(" left", "right  ", "  both  ")
#' hs_str_trim(trim, "left")
#' hs_str_trim(trim, "right")
#' hs_str_trim(trim, "both")
hs_str_trim <- function(string, side = c("both", "left", "right")) {
  side <- match.arg(side)
  
  switch(side,
         left =  hs_str_trim_left(string),
         right = hs_str_trim_right(string),
         both =  hs_str_trim_both(string)
  )
}

hs_str_trim_both <- function(string) {
  hs_str_replace_all(string, "^[ \t]+|[ \t]+$","") 
}

hs_str_trim_left <- function(string) {
  hs_str_replace_all(string, "^[ \t]+","") 
}

hs_str_trim_right <- function(string) {
  hs_str_replace_all(string, "[ \t]+$","") 
}