#include <stdio.h>
#include <assert.h>
#include <getopt.h>

static struct option long_options[] = {
	{"all", no_argument, 0,  0 },
	{"t0",  no_argument, 0,  0 },
	{"t1",  no_argument, 0,  0 },
	{"t2",  no_argument, 0,  0 },
	{"t3",  no_argument, 0,  0 },
	{"t4",  no_argument, 0,  0 },
	{0,     0,           0,  0 }
};

void test0(void) {};
void test1(void) {};
void test2(void) {};
void test3(void) {};
void test4(void) {};


static void (*tests[])(void) = {
	test0,
	test1,
	test2,
	test3,
	test4,
};

int main(int argc, char **argv) {
	while(1) {
		int option_index=0;
		char c = getopt_long(argc, argv, "",
				     long_options, &option_index);
		if (c == -1)
			break;
		switch(c) {
		case 0:
			printf("appel %d\n", option_index);
			if (option_index == 0)
				for(int i =0; i < 5; i++)
					tests[i]();
			else
				tests[option_index-1]();
			break;
		default:
			fprintf(stderr, "usage: gctests [--all] [--t[0-4]]\n");
		}
	}
	return 0;
}
