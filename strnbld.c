/** \file strnbld.c - string builder */

#include <stddef.h>

/**
 * strnbld - efficient string builder, like strncat but more efficient over multiple invocations
 *
 * Copies at most n characters from the source string to the destination.  
 * The source string must be null-terminated.
 * The strnbld function is meant to be invoked repeatedly to build up a string from several source strings.
 * It always returns a pointer to the '\0' character at the end of the destination.
 * On the first call, you pass in a destination pointer, a source pointer, and a count.
 * On subsequent calls, you pass in the previously-returned pointer, a source pointer, and a count.
 * The efficiency over strncat lies in not searching for the end of the destination string during each invocation.
 *
 * Like strncat(), if n characters are copied without reaching a '\0' in the source, 
 * the '\0' will be copied to the destination after the n'th character, which means n+1 characters 
 * will be copied to the destination in this case.  Ensure enough room for the potential extra character.
 * 
 * The n parameter applies to each invocation, not to the total for all invocations.
 * 
 * \param dest - The destination pointer
 * \param src  - The source pointer
 * \param n    - The maximum number of characters to copy from src to dest
 * \return   Pointer to the end of the destination string - the next destination
 */
char *strnbld(char *dest, char const *src, size_t n) {
	int count = 0;
	while(count < n && (*dest = *src++)) {
		dest++;
		count++;
	}
	if(count >= n) {
		*dest = '\0';
	}
	return dest;
}
