include ../user.cfg
include ../esp82xx/common.mf

CC = gcc
CFLAGS= -std=gnu99 -Wall -Wextra -O2 -march=native $(OPTS)
LOADLIBES = -lm
TARGET = arkensend

$(TARGET) : $(TARGET).o

clean :
	rm -rf $(TARGET).o $(TARGET) *~

