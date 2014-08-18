CFLAGS = -Wall -O3
CC=gcc -std=c1x

.c.o :
	${CC} ${CFLAGS} -c $<

all : doc test

doc : strbld.c strnbld.c strbld.h Doxyfile
	doxygen Doxyfile

test : test_strbld.txt test_strnbld.txt test_multi_strbld.txt

test_strbld.txt : test_strbld
	./$? > $@

test_strnbld.txt : test_strnbld
	./$? > $@

test_multi_strbld.txt : test_multi_strbld
	./$? > $@

test_strbld : test_strbld.o strbld.o strnbld.o
	${CC} ${CFLAGS} -o $@ test_strbld.o strbld.o strnbld.o

test_strnbld : test_strnbld.o strnbld.o
	${CC} ${CFLAGS} -o $@ test_strnbld.o strnbld.o

test_multi_strbld : test_multi_strbld.o strbld.o
	${CC} ${CFLAGS} -o $@ test_multi_strbld.o strbld.o

test_strbld.o : test_strbld.c

test_strnbld.o : test_strnbld.c

test_multi_strbld.o : test_multi_strbld.c

strbld.o : strbld.c

strnbld.o : strnbld.c

clean :
	rm -f *.o

clean_targets :
	rm -f *.o
	rm -f test_strbld
	rm -f test_strnbld
	rm -f test_multi_strbld
	rm -f test_*.txt
	rm -rf html
	rm -rf man
