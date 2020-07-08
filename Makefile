

default: carrace

carrace: carrace.c
	gcc -O3 -o carrace carrace.c -lpthread

clean:
	rm -rf carrace
