CC = clang++
CFLAGS = -std=c++11 -g

driver: driver.cpp ColumnSort.hpp
	$(CC) $(CFLAGS) -o driver driver.cpp
.PHONY: clean
clean:
	rm -rf driver