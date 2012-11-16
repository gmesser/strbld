// test_multi_strbld.c - test the multi string macro calling the string builder

#include <stdio.h>
#include <string.h>

#include "strbld.h"

int main(int argc, char *argv[]) {
	char mydest[20];
	char *strings[] = {"Say", " ", "hello", " ", "world"};

	memset(mydest, 0, sizeof(mydest));
	multi_strbld(mydest, strings[0], strings[1], strings[2], strings[3], strings[4]);
	printf("test_multi_strbld - using multi_strbld: Final string = [%s]\n", mydest);
	
	return 0;
}
