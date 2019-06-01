#include <Rcpp.h>
#include <hs.h>
#include <iostream>

static int countHandler(unsigned int id, unsigned long long from,
                        unsigned long long to, unsigned int flags, void *ctx) {
  size_t *matches = reinterpret_cast<size_t *>(ctx);
  (*matches)++;
  return 0;
}

//' Count the number of matches in a string.
//'
//' @param string Input character vector.
//' @param pattern Pattern to look for.
//'
//' @return An integer vector.
//' @export
//'
//' @examples
//' fruit <- c("apple", "banana", "pear", "pineapple")
//' str_count(fruit, "a")
//' str_count(fruit, "p")
//' str_count(fruit, "e")
// [[Rcpp::export]]
Rcpp::IntegerVector hs_str_count(Rcpp::CharacterVector string, 
                                 Rcpp::String pattern) {
    int n = string.size();
    Rcpp::IntegerVector out(n);
    std::string cppstring, cpppattern;
    cpppattern = std::string(pattern);
    hs_database_t *database;
    hs_compile_error_t *compile_err;
    hs_compile(cpppattern.c_str(), HS_FLAG_DOTALL, HS_MODE_BLOCK,
               NULL, &database, &compile_err);
    hs_scratch_t *scratch = NULL;
    hs_alloc_scratch(database, &scratch);
    size_t matchCount;
    for(int i = 0; i < n; ++i) {
      matchCount = 0;
      if (string[i] == NA_STRING) {
        out[i] = NA_INTEGER;
      } else {
        cppstring = std::string(string[i]);
        hs_scan(database, cppstring.c_str(), cppstring.size(), 0,
                scratch, countHandler, &matchCount);
        out[i] = matchCount;
      }
    }
    hs_free_scratch(scratch);
    hs_free_database(database);
    return out;
}
