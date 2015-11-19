#include "utest.h"
#include "../src/elempool.h"


void test4(void)
{  
	struct Elem *e = allocElem();
	u_isnotnull("unexpected failure in allocation", e);
	e->val = 10;
	e->next = 0;
	gcElems(& e, 1);
	u_success("test4");
}
