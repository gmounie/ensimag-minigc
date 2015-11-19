#include "utest.h"
#include "../src/elempool.h"



void test2(void)
{
	/* Allocate all the 1000 elements */
	struct Elem *head = NULL;
	struct Elem *e = 0;
	for(int i=0; i < 1000; i++) {
		e = allocElem();
		u_isnotnull("unexpected allocation failure", e);
		
		e->val = i;
		e->next = head;
		head = e;
	}

	
	/* No element should be free */
	e = allocElem();
	u_isnull("unexpected allocation success", e);

	/* check the list */
	e = head;
	for(int j = 0; j < 1000; j++) {
		u_assert("incoherent val field in Elem",
			 e->val == (1000 -j - 1));
		e = e->next;
	}

	/* No element should be freed as all are in the list */
	gcElems(& head, 1);

	/* No element should be freed */
	e = allocElem();
	u_isnull("unexpected allocation success", e);

	/* check the list */
	e = head;
	for(int j = 0; j < 1000; j++) {
		u_assert("incoherent val field in Elem",
			 e->val == (1000 -j - 1));
		e = e->next;
	}
	
	/* free all elements */
	head = NULL;
	gcElems(& head, 1);
		
		
	/* Allocate all the 1000 elements */
	for(int i=0; i < 1000; i++) {
		e = allocElem();
		u_isnotnull("unexpected allocation failure", e);
		
		e->val = i;
		e->next = head;
		head = e;
	}
	/* No element should be free */
	e = allocElem();
	u_isnull("unexpected allocation success", e);

	/* free all elements */
	head = NULL;
	gcElems(& head, 1);

	u_success("test2");
}
