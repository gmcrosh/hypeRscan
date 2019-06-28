#include <Rcpp.h>
#include <iostream>
#include <vector>
#include <hs.h>
#include "location.h"

Rcpp::IntegerVector loc_helper(std::vector<Location> loc) {
  int n = loc.size();
  Rcpp::IntegerVector out(n*2);
  Location holder;
  for(int i = 0; i < n; ++i) {
    holder = loc[i];
    out[i] = holder.start;
    out[n + i] = holder.finish;
  }
  out.attr("dim") = Rcpp::Dimension(n, 2);
  Rcpp::colnames(out) = Rcpp::CharacterVector({"start", "end"});
  return out;
}

//' Locate the all instances of a pattern
//' 
//' @param string Input character vector.
//' @param pattern Pattern to look for.
//'
//' @return A list of integer matrix.
//' @export
//'
//' @examples
//' fruit <- c("apple", "banana", "pear", "pineapple")
//' hs_str_locate_all(fruit, "app")
//' hs_str_locate_all(fruit, "p")
// [[Rcpp::export]]
Rcpp::List hs_str_locate_all(Rcpp::CharacterVector string, 
                                  Rcpp::String pattern) {
    int n = string.size();
    Rcpp::List out(n);
    std::string cppstring, cpppattern;
    cpppattern = std::string(pattern);
    hs_database_t *database;
    hs_compile_error_t *compile_err;
    hs_compile(cpppattern.c_str(), HS_FLAG_SOM_LEFTMOST, HS_MODE_BLOCK,
               NULL, &database, &compile_err);
    hs_scratch_t *scratch = NULL;
    hs_alloc_scratch(database, &scratch);
    for(int i = 0; i < n; ++i) {
      std::vector<Location> loc;
      cppstring = std::string(string[i]);
      hs_scan(database, cppstring.c_str(), cppstring.size(), 0, scratch,
              locateAllHandler, &loc);
      out[i] = loc_helper(loc);
    }
    hs_free_scratch(scratch);
    hs_free_database(database);
    return out;
}
