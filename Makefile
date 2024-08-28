CC = gcc
#CC = clang
#CC = tcc

all:
  $(CC) termicalc.c tinyexpr.c -lm -O3 -o calc
