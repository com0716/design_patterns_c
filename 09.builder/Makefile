#Makefile for main.cpp

SRCS = main.cpp
OBJS = ${SRCS:.cpp=.o}
EXEC = demo

CC = g++
CC_FLAGS = -Wall -g

.PHONY:default clean distclean
default:$(OBJS)
	$(CC) $(CC_FLAGS) $(OBJS) -o $(EXEC)

.cpp.o:
	$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	rm -f *.o

distclean:clean
	rm -f $(EXEC)

