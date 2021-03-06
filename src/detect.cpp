#include <Rcpp.h>
#include <hs.h>
#include <iostream>
#include "handler.h"

//' Detect if the pattern is in a string
//' 
//' @param string Input character vector.
//' @param pattern Pattern to look for.
//'
//' @return A logical vector.
//' @export
//'
//' @examples
//' fruit <- c("apple", "banana", "pear", "pineapple")
//' hs_str_detect(fruit, "app")
//' hs_str_detect(fruit, "p")
// [[Rcpp::export]]
Rcpp::LogicalVector hs_str_detect(Rcpp::CharacterVector string, 
                                  Rcpp::String pattern) {
    int n = string.size();
    Rcpp::LogicalVector out(n);
    std::string cppstring, cpppattern;
    cpppattern = std::string(pattern);
    bool matchDetect;
    hs_database_t *database;
    hs_compile_error_t *compile_err;
    hs_compile(cpppattern.c_str(), HS_FLAG_SINGLEMATCH, HS_MODE_BLOCK, NULL,
               &database, &compile_err);
    hs_scratch_t *scratch = NULL;
    hs_alloc_scratch(database, &scratch);
    for(int i = 0; i < n; ++i) {
      if (string[i] == NA_STRING) {
        out[i] = NA_LOGICAL;
      } else {
        matchDetect = false;
        cppstring = std::string(string[i]);
        hs_scan(database, cppstring.c_str(), cppstring.size(), 0, scratch,
                detectHandler, &matchDetect);
        out[i] = matchDetect;
      }
    }
    hs_free_scratch(scratch);
    hs_free_database(database);
    return out;
}
