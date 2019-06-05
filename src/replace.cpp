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

//' Replace the first instance of a pattern
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
//' hs_str_replace(fruit, "app","simi")
//' hs_str_replace(fruit, "p", "P)
// [[Rcpp::export]]
Rcpp::CharacterVector hs_str_replace(Rcpp::CharacterVector string, 
                                   Rcpp::String pattern,
                                   Rcpp::String replacement) {
    int n = string.size();
    Rcpp::CharacterVector out(n);
    std::string str, pat, rep;
    pat = std::string(pattern);
    rep = std::string(replacement);
    hs_database_t *database;
    hs_compile_error_t *compile_err;
    hs_compile(pat.c_str(), HS_FLAG_SOM_LEFTMOST, HS_MODE_BLOCK,
               NULL, &database, &compile_err);
    hs_scratch_t *scratch = NULL;
    hs_alloc_scratch(database, &scratch);
    for(int i = 0; i < n; ++i) {
      if (string[i] == NA_STRING) {
        out[i] = NA_STRING;
      } else {
        Location loc;
        loc.finish = 0;
        loc.start = 0;
        str = std::string(string[i]);
        hs_scan(database, str.c_str(), str.size(), 0, scratch,
                locateHandler, &loc);
        if (loc.finish == 0) {
          out[i] = string[i];
        } else {
          out[i] = str.substr(0, loc.start) + rep + str.substr(loc.finish, str.size());
        }
      }
    }
    hs_free_scratch(scratch);
    hs_free_database(database);
    return out;
}
