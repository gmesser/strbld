/* strbld.c - string builder */

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
 * Returns:   Pointer to the end of the destination string
 */
char *strbld(char *dest, const char *src) {
	while((*dest = *src++)) {
		dest++;
	}
	return dest;
}

