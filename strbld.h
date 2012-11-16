/* strbld.h - string builder */

#ifndef STRBLD_H_INCLUDED
#define STRBLD_H_INCLUDED

#include <stdlib.h>

// c99 variadic macro
#define multi_strbld(dest, ...) {\
	char *d = NULL;\
	for (char **iter = (char*[]){__VA_ARGS__, NULL}; *iter; iter++) {\
		if (d == NULL) {\
			d = strbld(dest, *iter);\
		}\
		else {\
			d = strbld(d, *iter);\
		}\
	}\
}

#ifdef __cplusplus
extern "C" {
#endif

char *strbld(char *dest, const char *src);
char *strnbld(char *dest, const char *src, size_t n);

#ifdef __cplusplus
}
#endif

#endif /* STRBLD_H_INCLUDED */
