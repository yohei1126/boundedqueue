#LIB = /usr/local/lib
LIB = /Users/yohei/usr/lib
GMOCK_INCLUDE = /Users/yohei/usr/gmock/include
GTEST_INCLUDE = /Users/yohei/usr/gmock/gtest/include

all: BoundedQueueTest
	./BoundedQueueTest

BoundedQueueTest: BoundedQueueTest.o
	g++ -o BoundedQueueTest $(LIB)/libgmock_main.a $(LIB)/libgmock.a $(LIB)/libgtest.a BoundedQueueTest.o

BoundedQueueTest.o: BoundedQueueTest.cpp BoundedQueue.h QueueControl.h
	g++ -c -I$(GMOCK_INCLUDE) -I$(GTEST_INCLUDE) BoundedQueueTest.cpp

clean: 
	rm *.o
	rm BoundedQueueTest

