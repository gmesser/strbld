// test_strbld.c - test string builder and verify the behavior by
//                 performing the same procedures with strcat

#include <stdio.h>
#include <string.h>

#include "strbld.h"

int main(int argc, char *argv[]) {
	int i;
	char mydest[20];
	char *ret;
	char *strings[] = {"Say", " ", "hello", " ", "world", NULL};
	int numstrings = (sizeof(strings) / sizeof(strings[0])) - 1;

	memset(mydest, 0, sizeof(mydest));
	for(i = 0; i < numstrings; i++) {
		if(i == 0) {
			ret = strbld(mydest, strings[i]);
		}
		else {
			ret = strbld(ret, strings[i]);
		}
	}
	printf("test_strbld - using strbld: Final string = [%s]\n", mydest);

	memset(mydest, 0, sizeof(mydest));
	for(i = numstrings - 1; i >= 0; i--) {
		if(i == numstrings - 1) {
			ret = strbld(mydest, strings[i]);
		}
		else {
			ret = strbld(ret, strings[i]);
		}
	}
	printf("test_strbld - using strbld: Final string = [%s]\n", mydest);

	memset(mydest, 0, sizeof(mydest));
	ret = strbld_array(mydest, (const char **) strings);
	printf("test_strbld - using strbld_array: Final string = [%s]\n", mydest);

	memset(mydest, 0, sizeof(mydest));
	for(i = 0; i < numstrings; i++) {
		if(i == 0) {
			ret = strcat(mydest, strings[i]);
		}
		else {
			ret = strcat(mydest, strings[i]);
		}
	}
	printf("test_strbld - using strcat: Final string = [%s]\n", mydest);

	memset(mydest, 0, sizeof(mydest));
	for(i = numstrings - 1; i >= 0; i--) {
		if(i == numstrings - 1) {
			ret = strcat(mydest, strings[i]);
		}
		else {
			ret = strcat(mydest, strings[i]);
		}
	}
	printf("test_strbld - using strcat: Final string = [%s]\n", mydest);

	return 0;
}

