#include <Rcpp.h>
#include <iostream>
#include <hs.h>

class Location {
  public:
  int start;
  int finish;
};

static int locateHandler(unsigned int id, unsigned long long from,
                        unsigned long long to, unsigned int flags, void *ctx) {
  Location *loc = reinterpret_cast<Location *>(ctx);
  if(loc->finish == 0) {
    loc->start = static_cast<int>(from);
    loc->finish = static_cast<int>(to);
  }
  return 0;
}

// [[Rcpp::export]]
Rcpp::IntegerVector hs_str_location(Rcpp::CharacterVector Rstring, 
                                    Rcpp::String Rpattern) {
    int n = Rstring.size();
    Rcpp::IntegerVector out(n*2);
    std::string cppstring, cpppattern;
    cpppattern = std::string(Rpattern);
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
      cppstring = std::string(Rstring[i]);
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
