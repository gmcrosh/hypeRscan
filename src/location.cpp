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