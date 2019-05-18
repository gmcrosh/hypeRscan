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
int hs_str_count(Rcpp::String Rstring, Rcpp::String Rpattern) {
  std::string cppstring, cpppattern;
  cppstring = std::string(Rstring);
  cpppattern = std::string(Rpattern);
  size_t matchCount;
  matchCount = 0;
  hs_database_t *database;
  hs_compile_error_t *compile_err;
  hs_compile(cpppattern.c_str(), HS_FLAG_DOTALL, HS_MODE_BLOCK, NULL, &database, &compile_err);
  hs_scratch_t *scratch = NULL;
  hs_alloc_scratch(database, &scratch);
  hs_scan(database, cppstring.c_str(), cppstring.size(), 0, scratch, countHandler, &matchCount);
  return matchCount;
}
