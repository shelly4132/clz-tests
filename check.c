#include <stdio.h>
#include <assert.h>
#include <limits.h>

#include "clz.h"



int main(){

	for(uint32_t i=1; i<UINT_MAX; i++){
#if defined(ITERATIVE)
		assert(iterative_clz(i) == __builtin_clz(i));
#endif
#if defined(BINARY)
		assert(binary_clz(i) == __builtin_clz(i));
#endif
#if defined(BYTE)
		assert(byte_clz(i) == __builtin_clz(i));
#endif
#if defined(RECURSIVE)
		assert(recursive_clz(i, 16) == __builtin_clz(i));
#endif
	}
	printf("Done!\n");
	return 0;

}