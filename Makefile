CC = gcc
CFLAGS = -O0 -std=gnu99 -Wall
EXECUTABLE = \
	check_iterative check_binary gettime \
	check_byte check_recursive

default: clz.o
	$(CC) $(CFLAGS) clz.o check.c -DITERATIVE -o check_iterative
	$(CC) $(CFLAGS) clz.o check.c -DBINARY -o check_binary
	$(CC) $(CFLAGS) clz.o check.c -DBYTE -o check_byte
	$(CC) $(CFLAGS) clz.o check.c -DRECURSIVE -o check_recursive
	$(CC) $(CFLAGS) clz.o gettime.c -o gettime

.PHONY: clean default

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@ 

check: default
	time ./check_iterative
	time ./check_binary
	time ./check_byte
	time ./check_recursive

gencsv: default
	for i in `seq 1000000 5000 4200000000`; do \
		printf "%d," $$i;\
		./gettime $$i; \
	done > result_clock_gettime.csv	

plot: result_clock_gettime.csv
	gnuplot scripts/runtime.gp


clean:
	rm -f $(EXECUTABLE) *.o *.s result_clock_gettime.csv runtime.png
