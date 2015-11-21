#include "utest.h"
#include "../src/elempool.h"
#include "../src/bitset1000.h"


void test1(void)
{
	bt1k_init();
	initElems();
	for(int i=0; i < 1001; i++) {
		struct Elem *e = allocElem();
		u_isnotnull("unexpected allocation failure", e);
		
		e->val = i;
		e->next = 0;
		e = NULL;
		gcElems(& e, 1);
	}
	u_success("test1");
	bt1k_destroy();
}
