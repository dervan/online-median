CC=g++
CFLAGS=-O3
BINS=array_median test_generator/generator

all: $(BINS)
	
array_median: src/main.cpp src/sorted_array.cpp
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f $(BINS)
