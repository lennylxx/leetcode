CC = gcc
CXX = g++
CFLAGS = -std=c99 -Wall -lm
CXXFLAGS = -std=c++11 -Wall

C_SRCS = $(wildcard src/*.c)
C_OUTS = $(patsubst %.c, %, $(C_SRCS))
CXX_SRCS = $(wildcard src/*.cpp)
CXX_OUTS = $(patsubst %.cpp, %, $(CXX_SRCS))

.PHONY: clean

all: $(C_OUTS) $(CXX_OUTS)

%.out : %.c
	$(CC) $(CFLAGS) $< -o $@

%.out : %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	$(RM) $(C_OUTS) $(CXX_OUTS)
