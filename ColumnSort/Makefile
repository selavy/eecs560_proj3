CC = clang++
CFLAGS = -std=c++11 -g -fsanitize=address -fno-omit-frame-pointer

driver: driver.cpp ColumnSort.hpp
	$(CC) $(CFLAGS) -o driver driver.cpp
.PHONY: clean
clean:
	rm -rf driver