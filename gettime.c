#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "clz.h"

#define CLOCK_ID CLOCK_MONOTONIC_RAW
#define ONE_SEC 1000000000.0


int main(int argc, char const *argv[]){
	struct timespec start = {0, 0};
    struct timespec end = {0, 0};

    if (argc < 2) return -1;

    int N = atoi(argv[1]);
    double time;

    //iterative
	clock_gettime(CLOCK_ID, &start);
    iterative_clz(N);
    clock_gettime(CLOCK_ID, &end);
    time = (double)(end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/ONE_SEC;
	printf("%lf,", time);

	//binary search
	clock_gettime(CLOCK_ID, &start);
    binary_clz(N);
    clock_gettime(CLOCK_ID, &end);
    time = (double)(end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/ONE_SEC;
	printf("%lf,", time);

	//byte shift
	clock_gettime(CLOCK_ID, &start);
    byte_clz(N);
    clock_gettime(CLOCK_ID, &end);
    time = (double)(end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/ONE_SEC;
	printf("%lf,", time);

	//recursive
	clock_gettime(CLOCK_ID, &start);
    recursive_clz(N, 16);
    clock_gettime(CLOCK_ID, &end);
    time = (double)(end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/ONE_SEC;
	printf("%lf\n", time);


	return 0;
}