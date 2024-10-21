.PHONY: clean

test: hw3.h hw3.c
	clang -wall -o test hw3.c
clean:
	rm -rf a.out test
