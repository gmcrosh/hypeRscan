#include <Rcpp.h>
#include <iostream>
#include <hs.h>

static int countHandler(unsigned int id, unsigned long long from,
                        unsigned long long to, unsigned int flags, void *ctx) {
  size_t *matches = (size_t *)ctx;
  (*matches)++;
  return 0;
}

// [[Rcpp::export]]
Rcpp::IntegerVector hs_str_count(Rcpp::CharacterVector Rstring, Rcpp::String Rpattern) {
    int n = Rstring.size();
    Rcpp::IntegerVector out(n);
    std::string cppstring, cpppattern;
    cpppattern = std::string(Rpattern);
    hs_database_t *database;
    hs_compile_error_t *compile_err;
    hs_compile(cpppattern.c_str(), HS_FLAG_DOTALL, HS_MODE_BLOCK, NULL, &database, &compile_err);
    hs_scratch_t *scratch = NULL;
    hs_alloc_scratch(database, &scratch);
    size_t matchCount;
    for(int i = 0; i < n; ++i) {
      matchCount = 0;
      if (Rstring[i] == NA_STRING) {
        out[i] = NA_INTEGER;
      }
      else {
        cppstring = std::string(Rstring[i]);
        hs_scan(database, cppstring.c_str(), cppstring.size(), 0, scratch, countHandler, &matchCount);
        out[i] = matchCount;
      }
    }
    hs_free_scratch(scratch);
    hs_free_database(database);
    return out;
}