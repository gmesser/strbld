/** \file strbld.h - string builder */

/** \mainpage
 Efficient C string building functions.
 */

#ifndef STRBLD_H_INCLUDED
#define STRBLD_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

char *strbld(char *dest, char const *src);
char *strbld_array(char *dest, char const *src[]);
char *strnbld(char *dest, char const *src, size_t n);

#ifdef __cplusplus
}
#endif

#if __STDC_VERSION__ >= 199901L
// c99 or better
/**
 * multi_strbld - macro to build up a string from source string parameters
 *
 * This macro calls uses strbld_array() to build up the destination string.
 *
 * \param dest - The destination pointer - must be large enough to handle
 *							all the strings sent in the parameter list
 * \param ... - The source pointers
 */
#define multi_strbld(dest, ...) {\
	strbld_array(dest, (char const *[]){__VA_ARGS__, NULL});\
}
#endif

#endif /* STRBLD_H_INCLUDED */
