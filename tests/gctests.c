#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <getopt.h>
#include "utest.h"

static struct option long_options[] = {
	{"all", no_argument, 0,  0 },
	{"t0",  no_argument, 0,  1 },
	{"t1",  no_argument, 0,  2 },
	{"t2",  no_argument, 0,  3 },
	{"t3",  no_argument, 0,  4 },
	{"t4",  no_argument, 0,  5 },
	{0,     0,           0,  0 }
};

extern void test0(void);
extern void test1(void);
extern void test2(void);
extern void test3(void);
extern void test4(void);


static void (*tests[])(void) = {
	test0,
	test1,
	test2,
	test3,
	test4,
};

void usage(char *aname) {
  fprintf(stderr, "usage: %s {--all | --t{0-4}}\n", aname);  
}

/* error count variable instanciation */
int u_errnb = 0;

int main(int argc, char **argv) {
	bool noargs = true;
	while(1) {
		int option_index=0;
		int nopt = getopt_long(argc, argv, "",
				     long_options, &option_index);
		if (nopt == -1) {
			if (noargs)
				usage(argv[0]);
			break;
		}
		switch(nopt) {
		case 0:
			for(int i =0; i < 5; i++)
				tests[i]();
			break;
		default:
			if (1 <= nopt && nopt <= 5)
				tests[nopt-1]();
			else
			  usage(argv[0]);
			break;
		}
		noargs = false;
	}
	fprintf(stderr,"Total number of errors: %d\n", u_errnb);
	return u_errnb;
}
