#ifndef ELEM_H
#define ELEM_H

struct Elem {
	int val;
	struct Elem *next;
};

extern struct Elem* allocElem();
extern gcElems( struct Elem ** heads, int nbheads);
extern void initElems();

#endif
