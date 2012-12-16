/* strbld.c - string builder */

#include <stdlib.h>
#include "strbld.h"

/*
 * strbld - efficient string builder, like strcat but more efficient over multiple invocations
 *
 * Copies the source string to the destination.  
 * The source string must be null-terminated.
 * The strbld function is meant to be invoked repeatedly to build up a string from several source strings.
 * It always returns a pointer to the '\0' character at the end of the destination.
 * On the first call, you pass in a destination pointer and a source pointer.
 * On subsequent calls, you pass in the previously-returned pointer and a source pointer.
 * The efficiency over strcat lies in not searching for the end of the destination string during each invocation.
 *
 * Parameter: dest - The destination pointer
 * Parameter: src  - The source pointer
 * Returns:   Pointer to the end of the destination string - the next destination
 */
char *strbld(char *dest, const char *src) {
	while((*dest = *src++)) {
		dest++;
	}
	return dest;
}

/**
 * strbld_array - build up a string from an array of strings
 *
 * This function is called by the multi_strbld macro.  It can also be
 * called directly with an array.  It uses repeated calls to strbld()
 * to build up the destination string.
 *
 * Parameter: dest - The destination pointer
 * Parameter: src  - The array of source pointers - last element must be NULL
 * Returns:   Pointer to the end of the destination string - the next destination
 */
char *strbld_array(char *dest, const char *src[]) {
	char *d;
	for (int i = 0; src[i] != NULL; i++) {
		if (i == 0) {
			d = strbld(dest, src[i]);
		}
		else {
			d = strbld(d, src[i]);
		}
	}
	return d;
}

