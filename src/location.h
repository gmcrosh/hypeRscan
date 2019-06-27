#ifndef LOCATION
#define LOCATION

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
#endif