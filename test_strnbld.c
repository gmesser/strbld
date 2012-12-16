// test_strnbld.c - test string builder and verify the behavior by
//                  performing the same procedures with strncat

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "strbld.h"

int main(int argc, char *argv[]) {
	int i;
	char mydest[20];
	char *ret;
	int n;
	char *strings[] = {"Say", " ", "hello", " ", "world"};
	int numstrings = 5;

	for(n = 2; n <= 6; n++) {
		memset(mydest, '#', sizeof(mydest));
		mydest[sizeof(mydest) - 1] = '\0';
		for(i = 0; i < numstrings; i++) {
			if(i == 0) {
				ret = strnbld(mydest, strings[i], n);
			}
			else {
				ret = strnbld(ret, strings[i], n);
			}
		}
		printf("test_strnbld - using strnbld (%d): Final string = [%s]\n", n, mydest);

		memset(mydest, '#', sizeof(mydest));
		mydest[sizeof(mydest) - 1] = '\0';
		for(i = numstrings - 1; i >= 0; i--) {
			if(i == numstrings - 1) {
				ret = strnbld(mydest, strings[i], n);
			}
			else {
				ret = strnbld(ret, strings[i], n);
			}
		}
		printf("test_strnbld - using strnbld (%d): Final string = [%s]\n", n, mydest);
	}

	for(n = 2; n <= 6; n++) {
		memset(mydest, '#', sizeof(mydest));
		mydest[0] = '\0';
		mydest[sizeof(mydest) - 1] = '\0';
		for(i = 0; i < numstrings; i++) {
			if(i == 0) {
				ret = strncat(mydest, strings[i], n);
			}
			else {
				ret = strncat(mydest, strings[i], n);
			}
		}
		printf("test_strnbld - using strncat (%d) for comparison: Final string = [%s]\n", n, mydest);

		memset(mydest, '#', sizeof(mydest));
		mydest[0] = '\0';
		mydest[sizeof(mydest) - 1] = '\0';
		for(i = numstrings - 1; i >= 0; i--) {
			if(i == numstrings - 1) {
				ret = strncat(mydest, strings[i], n);
			}
			else {
				ret = strncat(mydest, strings[i], n);
			}
		}
		printf("test_strnbld - using strncat (%d) for comparison: Final string = [%s]\n", n, mydest);
	}

	return 0;
}

