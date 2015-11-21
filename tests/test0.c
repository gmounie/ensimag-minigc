#include "utest.h"
#include "../src/elempool.h"
#include "../src/bitset1000.h"


void test0(void)
{  
	bt1k_init();
	initElems();
	struct Elem *e = allocElem();
	u_isnotnull("unexpected allocation failure", e);
	e->val = 10;
	e->next = 0;
	/* free all the elements */
	gcElems(& e, 1);
	/* free all the elements */
	gcElems(& e, 0);
	u_success("test0");
	bt1k_destroy();
}
