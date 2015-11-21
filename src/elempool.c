#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "elempool.h"
#include "bitset1000.h"

static unsigned char *memoireElemPool = 0;

/**
   Fonction allouant un element
*/
struct Elem* allocElem() {
	/* ajouter votre code ici / add your code here */
	for(int i = 0; i < 1000; i++) {
		if (! bt1k_get(i)) {
			bt1k_set(i, true);
			return ((struct Elem*) memoireElemPool)+i;
		}
	}
	return 0;
}

/**
   Fonction ramasse-miette sur les elements qui ne sont pas
   atteignables depuis les têtes de listes
*/
void gcElems( struct Elem ** heads, int nbheads) {
	/* ajouter votre code ici / add your code here */
	bt1k_reset();
	for(int i=0; i < nbheads; i++) {
		struct Elem *cour= heads[i];
		while(cour != NULL) {
			int index = (cour - ((struct Elem *) memoireElemPool));
			bt1k_set(index, true);
			cour = cour->next;
		}
	}
}


void freepool(void) {
	assert(memoireElemPool != 0);
	free(memoireElemPool);
}

void initElems() {
	bt1k_reset();
	if (! memoireElemPool) {
		memoireElemPool = malloc(1000 * sizeof(struct Elem));
		atexit(freepool);
	}
	memset(memoireElemPool, 0, 1000 * sizeof(struct Elem));
}
