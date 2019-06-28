#include <Rcpp.h>
#include <iostream>
#include <vector>
#include <hs.h>
#include "location.h"

Rcpp::String replace_helper(std::vector<Location> loc,
                            std::string str,
                            std::string rep) {
  int n = loc.size();
  Location holder;
  Rcpp::String rout;
  std::string out = str;
  for(int i = n-1; i >= 0; --i) {
    holder = loc[i];
    out = out.substr(0, holder.start) + rep + out.substr(holder.finish, out.size());
  }
  rout = Rcpp::String(out);
  return rout;
}

//' Replace each instance of a pattern
//' 
//' @param string Input character vector.
//' @param pattern Pattern to look for.
//' @param replacement String to replace pattern with.
//'
//' @return A charcter vector.
//' @export
//'
//' @examples
//' fruit <- c("apple", "banana", "pear", "pineapple")
//' hs_str_replace_all(fruit, "app","simi")
//' hs_str_replace_all(fruit, "p", "P")
// [[Rcpp::export]]
Rcpp::CharacterVector hs_str_replace_all(Rcpp::CharacterVector string, 
                              Rcpp::String pattern,
                              Rcpp::String replacement) {
    int n = string.size();
    Rcpp::CharacterVector out(n);
    std::string cppstring, cpppattern, cpprep;
    cpppattern = std::string(pattern);
    cpprep = std::string(replacement);
    hs_database_t *database;
    hs_compile_error_t *compile_err;
    hs_compile(cpppattern.c_str(), HS_FLAG_SOM_LEFTMOST, HS_MODE_BLOCK,
               NULL, &database, &compile_err);
    hs_scratch_t *scratch = NULL;
    hs_alloc_scratch(database, &scratch);
    for(int i = 0; i < n; ++i) {
      if (string[i] == NA_STRING) {
        out[i] = NA_STRING;
      } else {
        std::vector<Location> loc;
        cppstring = std::string(string[i]);
        hs_scan(database, cppstring.c_str(), cppstring.size(), 0, scratch,
                locateAllHandler, &loc);
        out[i] = replace_helper(loc, cppstring, cpprep);
      }
    }
    hs_free_scratch(scratch);
    hs_free_database(database);
    return out;
}
