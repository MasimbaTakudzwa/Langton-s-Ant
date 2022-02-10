CC = gcc

library:
	$(CC) -fpic -c langton.c
	$(CC) -fpic -c visualiser.c
	$(CC) -shared -o libant.so visualiser.o langton.o -lncursesw
	$(CC) -c main.c
	$(CC) -c main.c
	$(CC) -o ant main.c libant.so

clean:
	rm *.o
	rm *.so

test:
	$(CC) -o test visualiser.c langton.c ./tests/test.c -lncursesw
	./test
