#include "utest.h"
#include "elempool.h"


void test0(void)
{  
	struct Elem *e = allocElem();
	e->val = 10;
	e->next = 0;
	gcElems(& e, 1);
	u_success("test0");
}
