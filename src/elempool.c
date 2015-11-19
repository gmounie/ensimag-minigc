#include <stdlib.h>
#include <string.h>
#include "elempool.h"
#include "bitset1000.h"

static unsigned char *memoireElemPool = 0;

/**
   Fonction allouant un element
*/
struct Elem* allocElem() {
	/* ajouter votre code ici / add your code here */
	return 0;
}

/**
   Fonction ramasse-miette sur les elements qui ne sont pas
   atteignables depuis les têtes de listes
*/
void gcElems( struct Elem ** heads, int nbheads) {
	/* ajouter votre code ici / add your code here */
}

void initElems() {
	bt1k_reset();
	if (! memoireElemPool)
	  memoireElemPool = malloc(1000 * sizeof(struct Elem));
	memset(memoireElemPool, 0, 1000 * sizeof(struct Elem));
}
