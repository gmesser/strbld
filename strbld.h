/* strbld.h - string builder */

#ifndef STRBLD_H_INCLUDED
#define STRBLD_H_INCLUDED

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

char *strbld(char *dest, const char *src);
char *strnbld(char *dest, const char *src, size_t n);

#ifdef __cplusplus
}
#endif

#endif /* STRBLD_H_INCLUDED */
