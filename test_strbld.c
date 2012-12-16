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

	/*
	 * Using strbld.
	 */
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

	/*
	 * Using strcat for comparison.
	 * Although you can call it the same way each time, which is easier to
	 * remember, it must search for the end of the string each time it
	 * has to append another string.
	 */
	memset(mydest, 0, sizeof(mydest));
	for(i = 0; i < numstrings; i++) {
		if(i == 0) {
			ret = strcat(mydest, strings[i]);
		}
		else {
			ret = strcat(mydest, strings[i]);
		}
	}
	printf("test_strbld - using strcat for comparison: Final string = [%s]\n", mydest);

	memset(mydest, 0, sizeof(mydest));
	for(i = numstrings - 1; i >= 0; i--) {
		if(i == numstrings - 1) {
			ret = strcat(mydest, strings[i]);
		}
		else {
			ret = strcat(mydest, strings[i]);
		}
	}
	printf("test_strbld - using strcat for comparison: Final string = [%s]\n", mydest);

	/*
	 * Using strbld_array.
	 */
	memset(mydest, 0, sizeof(mydest));
	ret = strbld_array(mydest, (const char **) strings);
	printf("test_strbld - using strbld_array: Final string = [%s]\n", mydest);

	/*
	 * Using strbld, strnbld, strbld_array, and strbld again in a mixed example.
	 * This is the last example in the README.md file using all of the functions.
	 */
	char *the_end = NULL;
	const char *the_arr[] = {"World", "!", NULL}; // The last element MUST be NULL
	char the_beginning[] = "012345678901234"; /// Contents: [012345678901234\0]
	printf("test_strbld - using strbld, strnbld, and strbld_array: Orig. string = [%s]\n", the_beginning);
	the_end = strbld(the_beginning, "Hello"); // Contents: [Hello\0678901234\0]
	printf("test_strbld - using strbld, strnbld, and strbld_array: Curr. string = [%s]\n", the_beginning);
	the_end = strnbld(the_end, " ", 1); //////// Contents: [Hello \078901234\0]
	printf("test_strbld - using strbld, strnbld, and strbld_array: Curr. string = [%s]\n", the_beginning);
	the_end = strbld_array(the_end, the_arr); // Contents: [Hello World!\034\0]
	printf("test_strbld - using strbld, strnbld, and strbld_array: Curr. string = [%s]\n", the_beginning);
	the_end = strbld(the_end, the_arr[1]); ///// Contents: [Hello World!!\04\0]
	printf("test_strbld - using strbld, strnbld, and strbld_array: Final string = [%s]\n", the_beginning);

	return 0;
}

