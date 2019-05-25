#include <Rcpp.h>
#include <hs.h>
#include <iostream>

static int detectHandler(unsigned int id, unsigned long long from,
                        unsigned long long to, unsigned int flags, void *ctx) {
  bool *matches = reinterpret_cast<bool *>(ctx);
  *matches = true;
  return 0;
}

// [[Rcpp::export]]
Rcpp::LogicalVector hs_str_detect(Rcpp::CharacterVector Rstring, 
                                  Rcpp::String Rpattern) {
    int n = Rstring.size();
    Rcpp::LogicalVector out(n);
    std::string cppstring, cpppattern;
    cpppattern = std::string(Rpattern);
    bool matchDetect;
    hs_database_t *database;
    hs_compile_error_t *compile_err;
    hs_compile(cpppattern.c_str(), HS_FLAG_SINGLEMATCH, HS_MODE_BLOCK, NULL,
               &database, &compile_err);
    hs_scratch_t *scratch = NULL;
    hs_alloc_scratch(database, &scratch);
    for(int i = 0; i < n; ++i) {
      matchDetect = false;
      cppstring = std::string(Rstring[i]);
      hs_scan(database, cppstring.c_str(), cppstring.size(), 0, scratch,
              detectHandler, &matchDetect);
      out[i] = matchDetect;
    }
    hs_free_scratch(scratch);
    hs_free_database(database);
    return out;
}
