CC = clang++
CFLAGS = -std=c++11 -fsanitize=address -fno-omit-frame-pointer

driver: driver.cpp InsertionSort.hpp
	$(CC) $(CFLAGS) -o driver driver.cpp
.PHONY: clean
clean:
	rm -rf driver