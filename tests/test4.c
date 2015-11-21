#include "utest.h"
#include "../src/elempool.h"


void test4(void)
{  
	initElems();
	/* Allocate all the 1000 elements */
	struct Elem *heads[1000] = {};
	struct Elem *e;

	for(int i=0; i < 1000; i++) {
		e = allocElem();
		u_isnotnull("unexpected allocation failure", e);
		
		e->val = i;
		e->next = heads[i];
		heads[i] = e;
	}
	/* No element should be free */
	e = allocElem();
	u_isnull("unexpected allocation success", e);

	/* check the list */
	for(int i = 0; i < 1000; i++) {
		u_assert("incoherent val field in Elem",
			 heads[i]->val == i);
		u_isnull("incoherent next field in Elem",
			 heads[i]->next);
	}

	/* free none of the elements */
	gcElems(heads, 1000);

	/* No element should be free */
	e = allocElem();
	u_isnull("unexpected allocation success", e);

	/* free half of the elements */
	gcElems(heads, 500);

	/* allocate 500 elements */
		for(int i=0; i < 1000; i++) {
		e = allocElem();
		u_isnotnull("unexpected allocation failure", e);
		
		e->val = i;
		e->next = heads[i];
		heads[i] = e;
	}
	/* No element should be free */
	e = allocElem();
	u_isnull("unexpected allocation success", e);

	/* check the list */
	for(int i = 0; i < 1000; i++) {
		u_assert("incoherent val field in Elem",
			 heads[i]->val == i);
		u_isnull("incoherent next field in Elem",
			 heads[i]->next);
	}
	
	/* free all elements */
	heads[0] = 0;
	gcElems(heads, 0);
	
	u_success("test4");
}
