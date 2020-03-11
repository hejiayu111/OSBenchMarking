#include <stdio.h>
#include <stdlib.h>
#include "rdtsc.h"

#define ITERATIONS 100000

int main(int argc, char* argv[]) {
    unsigned long long start, end;
	double res = 0.0;
    int i;
    
	for (i = 0; i < ITERATIONS; i++) {
		start = rdtsc();
		end = rdtsc();
		res += 1.0 * (end - start) / ITERATIONS;
	}

	printf("Time Register Average Reading Time: %f\n", res);
}
