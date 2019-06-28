#include <Rcpp.h>
#include <iostream>
#include <hs.h>
#include "location.h"

//' Locate the first instance of a pattern
//' 
//' @param string Input character vector.
//' @param pattern Pattern to look for.
//'
//' @return A integer matrix.
//' @export
//'
//' @examples
//' fruit <- c("apple", "banana", "pear", "pineapple")
//' hs_str_locate(fruit, "app")
//' hs_str_locate(fruit, "p")
// [[Rcpp::export]]
Rcpp::IntegerVector hs_str_locate(Rcpp::CharacterVector string, 
                                  Rcpp::String pattern) {
    int n = string.size();
    Rcpp::IntegerVector out(n*2);
    std::string cppstring, cpppattern;
    cpppattern = std::string(pattern);
    hs_database_t *database;
    hs_compile_error_t *compile_err;
    hs_compile(cpppattern.c_str(), HS_FLAG_SOM_LEFTMOST, HS_MODE_BLOCK,
               NULL, &database, &compile_err);
    hs_scratch_t *scratch = NULL;
    hs_alloc_scratch(database, &scratch);
    for(int i = 0; i < n; ++i) {
      Location loc;
      loc.finish = 0;
      loc.start = 0;
      cppstring = std::string(string[i]);
      hs_scan(database, cppstring.c_str(), cppstring.size(), 0, scratch,
              locateHandler, &loc);
      if (loc.finish == 0) {
        out[i] = NA_INTEGER;
        out[n + i] = NA_INTEGER;
      } else {
        out[i] = loc.start; 
        out[n + i] = loc.finish; 
      }
    }
    out.attr("dim") = Rcpp::Dimension(n, 2);
    Rcpp::colnames(out) = Rcpp::CharacterVector({"start", "end"});
    hs_free_scratch(scratch);
    hs_free_database(database);
    return out;
}
