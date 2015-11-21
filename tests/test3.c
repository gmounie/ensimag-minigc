#include "utest.h"
#include "../src/elempool.h"
#include "../src/bitset1000.h"


void test3(void)
{
	bt1k_init();
	initElems();
	struct Elem *head = NULL;
	struct Elem *e;

	/* allocate 2 * 500 but chain only one other 2 */
	for(int i=0; i < 500; i++) {
		e = allocElem();
		u_isnotnull("unexpected allocation failure", e);
		
		e = allocElem();
		u_isnotnull("unexpected allocation failure", e);
		
		e->val = i;
		e->next = head;
		head = e;
	}
	/* No element should be free */
	e = allocElem();
	u_isnull("unexpected allocation success", e);

	/* free the 500 elems not in the liste */
	gcElems( & head, 1);

	/* allocate 500 and chain them */	
	for(int i=0; i < 500; i++) {
		e = allocElem();
		u_isnotnull("unexpected allocation failure", e);

		e->val = 500 + i;
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
	u_isnull("incoherent end of list", e);

	/* free all elements */
	head = NULL;
	gcElems(& head, 1);

	u_success("test3");
	bt1k_destroy();
}
