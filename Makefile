CC = g++
CFLAGS = -std=c++11 -Ofast

//OBJS = SpeedTestAuxSorts.o
OBJS = ColumnSortTest.o

SpeedTestAuxSorts: $(OBJS)
	$(CC) $(CFLAGS) -o SpeedTestAuxSorts $(OBJS)
SpeedTestAuxSorts.o: SpeedTestAuxSorts.cpp
	$(CC) $(CFLAGS) -c SpeedTestAuxSorts.cpp
ColumnSortTest.o: ColumnSortTest.cpp
	$(CC) $(CFLAGS) -c ColumnSortTest.cpp
.PHONY:clean
clean:
	rm -rf $(OBJS) SpeedTestAuxSorts
