#ifndef UTEST_H
#define UTEST_H

/**
   Minimalist Unit testing, partially from an idea of
   http://www.jera.com/techinfo/jtns/jtn002.html

*/

#include <stdio.h>

#define FAIL(message) do { fprintf(stderr,"FAILURE: "##message##"\n"); return; } while(0)
#define OK(message) do { fprintf(stderr,"SUCCESS: "##message##"\n"); } while(0)


#define u_assert(message, test) do { if (!(test)) FAIL(message); } while(0)
#define u_isnull(message, test) do { if ((test) != NULL) FAIL(message); } while(0)
#define u_success(message) do { OK(message); } while(0)

#endif
