/* strbld.h - string builder */

#ifndef STRBLD_H_INCLUDED
#define STRBLD_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

char *strbld(char *dest, const char *src);
char *strbld_array(char *dest, const char *src[]);
char *strnbld(char *dest, const char *src, size_t n);

#ifdef __cplusplus
}
#endif

#if __STDC_VERSION__ >= 199901L
// c99
#define multi_strbld(dest, ...) {\
	strbld_array(dest, (const char*[]){__VA_ARGS__, NULL});\
}
#endif

#endif /* STRBLD_H_INCLUDED */
