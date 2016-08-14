CFLAGS := -fPIC

all:
	make detect
	make test

detect: detect.o
	$(CC) -fPIC -shared -o libBanXiaocaoDetector.so detect.o

test: test.o
	$(CC) -o test test.o -L. -lBanXiaocaoDetector

clean:
	find . -name "*.o" -exec rm '{}' ';'
	find . -name "*.so" -exec rm '{}' ';'
	rm test

