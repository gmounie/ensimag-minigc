#ifndef BITSET1000_H
#define BITSET1000_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
  bool bt1k_get(int n);
  void bt1k_set(int n, bool val);
  void bt1k_reset();

#ifdef __cplusplus
}
#endif

#endif
