#include <Rcpp.h>
#include <hs.h>
#include <iostream>
#include "handler.h"

//' Detect which strings match a pattern
//' 
//' @param string Input character vector.
//' @param pattern Pattern to look for.
//'
//' @return A integer vector of length of matches.
//' @export
//'
//' @examples
//' fruit <- c("apple", "banana", "pear", "pineapple")
//' hs_str_which(fruit, "a")
//' hs_str_which(fruit, "p")
// [[Rcpp::export]]
Rcpp::IntegerVector hs_str_which(Rcpp::CharacterVector string, 
                                 Rcpp::String pattern) {
    int n = string.size();
    Rcpp::IntegerVector out(n);
    std::string cppstring, cpppattern;
    cpppattern = std::string(pattern);
    bool matchDetect;
    hs_database_t *database;
    hs_compile_error_t *compile_err;
    hs_compile(cpppattern.c_str(), HS_FLAG_SINGLEMATCH, HS_MODE_BLOCK, NULL,
               &database, &compile_err);
    hs_scratch_t *scratch = NULL;
    hs_alloc_scratch(database, &scratch);
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
      if (string[i] != NA_STRING) {
        matchDetect = false;
        cppstring = std::string(string[i]);
        hs_scan(database, cppstring.c_str(), cppstring.size(), 0, scratch,
                detectHandler, &matchDetect);
        if (matchDetect) {
          out[cnt] = i + 1;
          cnt += 1;
        }
      }
    }
    hs_free_scratch(scratch);
    hs_free_database(database);
    return out[Rcpp::Range(0, cnt - 1)];
}
