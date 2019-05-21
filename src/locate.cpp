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
  if(loc->finish == 0) {
    loc->start = int(from);
    loc->finish = int(to);
  }
  return 0;
}

// [[Rcpp::export]]
IntegerVector hs_str_location(CharacterVector Rstring, String Rpattern) {
    int n = Rstring.size();
    IntegerVector out(n*2);
    string cppstring, cpppattern;
    cpppattern = string(Rpattern);
    hs_database_t *database;
    hs_compile_error_t *compile_err;
    hs_compile(cpppattern.c_str(), HS_FLAG_SOM_LEFTMOST, HS_MODE_BLOCK, NULL, &database, &compile_err);
    hs_scratch_t *scratch = NULL;
    hs_alloc_scratch(database, &scratch);
    for(int i = 0; i < n; ++i) {
      Location loc;
      loc.finish = 0;
      loc.start = 0;
      cppstring = string(Rstring[i]);
      hs_scan(database, cppstring.c_str(), cppstring.size(), 0, scratch, locateHandler, &loc);
      if (loc.finish == 0) {
        out[i] = NA_INTEGER;
        out[n + i] = NA_INTEGER;
      }
      else
      {
        out[i] = loc.start; 
        out[n + i] = loc.finish; 
      }
    }
    out.attr("dim") = Dimension(n, 2);
    colnames(out) = CharacterVector({"start","end"});
    hs_free_scratch(scratch);
    hs_free_database(database);
    return out;
}
