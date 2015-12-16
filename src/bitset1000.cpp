/**
   Copyright (C) 2015 by Gregory Mounie 
   
   This file is part of ExamGC

   ExamGC is free software: you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.


   ExamGC is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>. 
*/

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



