#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rdtsc.h"

#define LOOP 1000000
#define rdtsc_time 120

int main() {

    int loops = LOOP;
    unsigned long long start, end;
    int i=0;
    start = rdtsc();
    for (; i < loops; ++i) {}
    end = rdtsc();
	unsigned long long total = end - start;
    printf ("CPU iteration total time and average time: %llu  %f\n", total, (total-rdtsc_time)*1.0/loops);
}

