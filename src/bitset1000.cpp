#include <bitset>
#include "bitset1000.h"
#include <cassert>

using namespace std;

static bitset<1000> bitfield {};


void bt1k_reset() {
  bitfield.reset();;
}

void bt1k_set(int n, bool val) {
  assert(n >= 0 && n < 1000);

  bitfield[n] = val;
}

bool bt1k_get(int n) {
  assert(n >= 0 && n < 1000);

  return bitfield[n];
}



