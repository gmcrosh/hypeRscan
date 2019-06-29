#ifndef HANDLER
#define HANDLER

#include <Rcpp.h>

class Location {
public:
  int start;
  int finish;
};

int locateHandler(unsigned int id,
                  unsigned long long from,
                  unsigned long long to,
                  unsigned int flags,
                  void *ctx);

int locateAllHandler(unsigned int id,
                     unsigned long long from,
                     unsigned long long to, 
                     unsigned int flags, 
                     void *ctx);

Rcpp::String replace_helper(std::vector<Location> loc,
                            std::string str,
                            std::string rep);

int detectHandler(unsigned int id, 
                  unsigned long long from,
                  unsigned long long to,
                  unsigned int flags, 
                  void *ctx);

int countHandler(unsigned int id, 
                 unsigned long long from,
                 unsigned long long to, 
                 unsigned int flags, 
                 void *ctx);
#endif