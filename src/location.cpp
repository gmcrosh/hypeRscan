#include <vector>
#include "location.h"

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