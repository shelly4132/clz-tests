#include <stdio.h>
#include <stdint.h>

int iterative_clz(uint32_t x);
int binary_clz(uint32_t x);
int byte_clz(uint32_t x);
int recursive_clz(uint32_t x, int shift);