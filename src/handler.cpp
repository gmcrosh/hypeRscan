#include <vector>
#include <Rcpp.h>
#include "handler.h"

int locateHandler(unsigned int id,
                  unsigned long long from,
                  unsigned long long to,
                  unsigned int flags,
                  void *ctx) {
  Location *loc = reinterpret_cast<Location *>(ctx);
  if(loc->finish == 0) {
    loc->start = static_cast<int>(from);
    loc->finish = static_cast<int>(to);
  }
  return 0;
}

int locateAllHandler(unsigned int id,
                     unsigned long long from,
                     unsigned long long to, 
                     unsigned int flags, 
                     void *ctx) {
  std::vector<Location> *loc = reinterpret_cast<std::vector<Location> *>(ctx);
  
  Location newlocation;
  newlocation.start = static_cast<int>(from);
  newlocation.finish = static_cast<int>(to);
  loc->push_back(newlocation);
  return 0;
}

Rcpp::String replace_helper(std::vector<Location> loc,
                            std::string str,
                            std::string rep) {
  int n = loc.size();
  Location holder, holder2;
  Rcpp::String rout;
  std::string out = str;
  for(int i = n-1; i >= 0; --i) {
    holder = loc[i];
    if (i > 0) {
      holder2 = loc[i -1];
      if (holder.start != holder2.start) {
        out = out.substr(0, holder.start) + rep + out.substr(holder.finish, out.size());
      }
    } else {
      out = out.substr(0, holder.start) + rep + out.substr(holder.finish, out.size());
    }
  }
  rout = Rcpp::String(out);
  return rout;
}

int detectHandler(unsigned int id, unsigned long long from,
                         unsigned long long to, unsigned int flags, void *ctx) {
  bool *matches = reinterpret_cast<bool *>(ctx);
  *matches = true;
  return 0;
}

int countHandler(unsigned int id, unsigned long long from,
                 unsigned long long to, unsigned int flags, void *ctx) {
  size_t *matches = reinterpret_cast<size_t *>(ctx);
  (*matches)++;
  return 0;
}