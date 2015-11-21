#include "utest.h"
#include "../src/elempool.h"


void test0(void)
{  
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
}
