strbld
======

String builder, more efficient than strcat.

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

/*
 * strbld_array - build up a string from an array of strings
 *
 * This function is called by the multi_strbld macro.  It can also be
 * called directly with an array.
 *
 * Parameter: dest - The destination pointer
 * Parameter: src  - The array of source pointers - last element must be NULL
 * Returns:   Pointer to the destination string
 */

/*
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
 * Parameter: dest - The destination pointer
 * Parameter: src  - The source pointer
 * Parameter: n    - The maximum number of characters to copy from src to dest
 * Returns:   Pointer to the end of the destination string
 */

