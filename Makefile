app: sorts.o main.o
	gcc -shared -o libsorts.so sorts.o
	gcc -Wall -Werror main.o -L. -lsorts -o app

sorts.o: sorts.c
	gcc -fPIC -c sorts.c -o sorts.o

main.o: main.c
	gcc -c main.c -o main.o

.PHONY: all clean

clean:
	rm -f app libsorts.so *.o