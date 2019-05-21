#include <Rcpp.h>
#include <iostream>
#include <hs.h>

using namespace Rcpp;
using namespace std;

class Location {
  public:
  int start;
  int finish;
};

static int locateHandler(unsigned int id, unsigned long long from,
                        unsigned long long to, unsigned int flags, void *ctx) {
  Location *loc = (Location *)ctx;
  loc->start = from;
  loc->finish = to;
  return 0;
}

// [[Rcpp::export]]
NumericMatrix hs_str_location(CharacterVector Rstring, String Rpattern) {
    int n = Rstring.size();
    NumericMatrix out(n, 2);
    string cppstring, cpppattern;
    cpppattern = string(Rpattern);
    Location loc;
    hs_database_t *database;
    hs_compile_error_t *compile_err;
    hs_compile(cpppattern.c_str(), HS_FLAG_SINGLEMATCH, HS_MODE_BLOCK, NULL, &database, &compile_err);
    hs_scratch_t *scratch = NULL;
    hs_alloc_scratch(database, &scratch);
    for(int i = 0; i < n; ++i) {
      loc.finish = 0;
      cppstring = string(Rstring[i]);
      hs_scan(database, cppstring.c_str(), cppstring.size(), 0, scratch, locateHandler, &loc);
      if (loc.finish == 0) {
        out[i, 0] = NA_INTEGER;
        out[i, 1] = NA_INTEGER;
      }
      else
      {
        out[i, 0] = loc.start; 
        out[i, 1] = loc.finish; 
      }
    }
    hs_free_scratch(scratch);
    hs_free_database(database);
    return out;
}
