#ifndef UTEST_H
#define UTEST_H

/**
   Minimalist unit testing, very partially from an idea of
   http://www.jera.com/techinfo/jtns/jtn002.html

*/

#include <stdio.h>

/* u_errnb counts errors and must be instancied somewhere */
extern int u_errnb;


#define FAIL(message, test) do { fprintf(stderr,"FAILURE:(%s) %s; (%s, line %d)\n", #test, message, __FILE__, __LINE__); u_errnb++; return; } while(0)
#define OK(message) do { fprintf(stderr,"SUCCESS: %s\n", message); } while(0)


#define u_assert(message, test) do { if (!(test)) FAIL(message, test); } while(0)
#define u_isnull(message, test) do { if ((test) != NULL) FAIL(message, test); } while(0)
#define u_isnotnull(message, test) do { if ((test) == NULL) FAIL(message, test); } while(0)
#define u_success(message) do { OK(message); } while(0)



#endif
