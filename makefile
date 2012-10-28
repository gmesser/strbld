CFLAGS = -Wall

.c.o :
	${CC} ${CFLAGS} -c $<

all : test

test : test_strbld.txt test_strnbld.txt

test_strbld.txt : test_strbld
	./$? > $@

test_strnbld.txt : test_strnbld
	./$? > $@

test_strbld : test_strbld.o strbld.o
	${CC} ${CFLAGS} -o $@ test_strbld.o strbld.o

test_strnbld : test_strnbld.o strnbld.o
	${CC} ${CFLAGS} -o $@ test_strnbld.o strnbld.o

test_strbld.o : test_strbld.c

test_strnbld.o : test_strnbld.c

strbld.o : strbld.c

strnbld.o : strnbld.c

clean :
	rm -f *.o

clean_targets :
	rm -f *.o
	rm -f test_strbld
	rm -f test_strnbld
	rm -f test_str*.txt
