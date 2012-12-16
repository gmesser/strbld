strbld
======

String builder, more efficient than strcat.  There are three functions provided
here, and one macro.  The macro can be used when compiling is set up to allow
the 1999 C (c99) language syntax.

Each function returns a pointer to the end of the destination string.  You must
keep track of the beginning of the destination string.  The first call to one
of these functions and the subsequent calls are slightly different.

For example, assume there is a pointer called "the_beginning" that points to a
buffer that has room for 15 characters and a '\0' byte, and another pointer
called "the_end" that is NULL to start with:

<pre>
 char *the_beginning = "012345678901234"; // Contents: [012345678901234\0]
 char *the_end = NULL;
</pre>

The first call to either of these functions will look like this:

<pre>
 the_end = strbld(the_beginning, "Hello"); // Contents: [Hello\0678901234\0]
</pre>

Now "the_beginning" still points to the buffer, but "the_end" points to the
'\0' byte that was written at the end of the first string copied, "Hello".

All of the subsequent calls to either of these functions will look like this:

<pre>
 the_end = strbld(the_end, " "); //////////// Contents: [Hello \078901234\0]
 the_end = strbld(the_end, "World!"); /////// Contents: [Hello World!\034\0]
</pre>

Notice that the return value from the first call is used as the destination
parameter for all of the subsequent calls.  The return value points to the '\0'
byte at the end of the last string copied.  This is how the functions gain
their efficiency over strcat.  They do not need to search for the end of the
destination string each time they are called to append another string.

In the examples above, "the_beginning" always points to the beginning of the
destination string, and "the_end" always comes back from the function calls
pointing to the end of the last string that was appended.  That is where the
next appended string will go.

Mixed Use

One more thing: You can freely mix calls to any of these functions since they
all behave the same way.  You cannot, however, mix the execution of the macro
with calls to these functions because the macro does not return a pointer like
the functions do.

Here is a set of calls mixing calls to each of the functions to build up a
single string:

<pre>
 char *the_end = NULL;
 char *the_arr[] = {"World", "!", NULL}; // The last element MUST be NULL
 char *the_beginning = "012345678901234"; /// Contents: [012345678901234\0]
 the_end = strbld(the_beginning, "Hello"); // Contents: [Hello\0678901234\0]
 the_end = strnbld(the_end, " ", 1); //////// Contents: [Hello \078901234\0]
 the_end = strbld_array(the_end, the_arr); // Contents: [Hello World!\034\0]
 the_end = strbld(the_end, the_arr[1]); ///// Contents: [Hello World!!\04\0]
</pre>


<hr>

* strbld - efficient string builder, like strcat but more efficient over multiple invocations

Copies the source string to the destination.  
The source string must be null-terminated.
The strbld function is meant to be invoked repeatedly to build up a string from several source strings.
It always returns a pointer to the '\0' character at the end of the destination.
On the first call, you pass in a destination pointer and a source pointer.
On subsequent calls, you pass in the previously-returned next destination pointer and a source pointer.
The efficiency over strcat lies in not searching for the end of the destination string during each invocation.

Parameter: dest - The destination pointer<br>
Parameter: src  - The source pointer<br>
Returns:   Pointer to the end of the destination string<br>


<hr>

* strbld_array - build up a string from an array of strings

This function is called by the multi_strbld macro.  It can also be
called directly with an array.  It uses repeated calls to strbld()
to build up the destination string.
The source strings in the array must be null-terminated.
The strbld function is meant to be invoked repeatedly to build up a string from several source strings.
It always returns a pointer to the '\0' character at the end of the destination.
On the first call, you pass in a destination pointer and a source pointer.
On subsequent calls, you pass in the previously-returned next destination pointer and a source pointer.
The efficiency over strcat lies in not searching for the end of the destination string during each invocation.

Parameter: dest - The destination pointer<br>
Parameter: src  - The array of source pointers - last element must be NULL<br>
Returns:   Pointer to the end of the destination string<br>


<hr>

* strnbld - efficient string builder, like strncat but more efficient over multiple invocations

Copies at most n characters from the source string to the destination.  
The source string must be null-terminated.
The strnbld function is meant to be invoked repeatedly to build up a string from several source strings.
It always returns a pointer to the '\0' character at the end of the destination.
On the first call, you pass in a destination pointer, a source pointer, and a count.
On subsequent calls, you pass in the previously-returned next destination pointer, a source pointer, and a count.
The efficiency over strncat lies in not searching for the end of the destination string during each invocation.

Like strncat(), if n characters are copied without reaching a '\0' in the source, 
the '\0' will be copied to the destination after the n'th character, which means n+1 characters 
will be copied to the destination in this case.  Ensure enough room for the potential extra character.

The n parameter applies to each invocation, not to the total for all invocations.
 
Parameter: dest - The destination pointer<br>
Parameter: src  - The source pointer<br>
Parameter: n    - The maximum number of characters to copy from src to dest<br>
Returns:   Pointer to the end of the destination string<br>


<hr>

* multi_strbld - macro for easily calling strbld_array() with an arbitrary list of strings.

This macro does not return a pointer, so it cannot be freely mixed with calls
to the other functions.

Parameter:  dest - The destination pointer<br>
Parameters: A list of strings - the macro automatically adds the NULL as the last array element after the list of strings as required by strbld_array<br>
Returns:    There is no return value from this macro.<br>

