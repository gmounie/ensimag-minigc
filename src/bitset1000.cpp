#include <bitset>
#include "bitset1000.h"
#include <cassert>

using namespace std;


static bitset<1000> *pbitfield=0;

void bt1k_init() {
	pbitfield = new bitset<1000>();
	pbitfield->reset();
}

void bt1k_destroy() {
	delete pbitfield;
	pbitfield = 0;
}

void bt1k_reset() {
  pbitfield->reset();
}

void bt1k_set(int n, bool val) {
  assert(n >= 0 && n < 1000);

  (*pbitfield)[n] = val;
}

bool bt1k_get(int n) {
  assert(n >= 0 && n < 1000);

  return (*pbitfield)[n];
}



