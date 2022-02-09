CC == gcc

library:
	$(CC) -c visualiser.c langton.c -fpic
	$(CC) *.o -shared -o libant.so -lncursesw
	$(CC) -c main.c main.o
	$(CC) -o main.c main.o
	$(CC) -c main.c -o main.o
	$(CC) -o main main.o -L. -lant

clean:
	$(CC) rm *.o
	$(CC) rm *.so

test:
	$(CC) gcc -o test visualiser.c langton.c ./tests/test.c -lncursesw
	./test
