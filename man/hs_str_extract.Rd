% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/RcppExports.R
\name{hs_str_extract}
\alias{hs_str_extract}
\title{Extract the first instance of a pattern}
\usage{
hs_str_extract(string, pattern)
}
\arguments{
\item{string}{Input character vector.}

\item{pattern}{Pattern to look for.}
}
\value{
A charcter vector.
}
\description{
Extract the first instance of a pattern
}
\examples{
fruit <- c("apple", "banana", "pear", "pineapple")
hs_str_extract(fruit, "[aeoiu]")
}
