#include "rdtsc.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEGABYTE 1048576
#define L3 (8*MEGABYTE)
#define REPEAT 1

void measure_bandwidth(unsigned char* small_array, size_t memory_size){   

    unsigned long long start,end;
    struct timespec read_start,read_end;

    // check write bandwith
    clock_gettime(CLOCK_REALTIME,&read_start);
    for (unsigned int j = 0; j < REPEAT; j++){
        for (size_t k =0; k <memory_size;k++){
            small_array[k] = '1';
        }
    }
    clock_gettime(CLOCK_REALTIME, &read_end);

    double time_sec = (read_end.tv_sec * 1e9 - read_start.tv_sec * 1e9);
    double time_nsec = (read_end.tv_nsec - read_start.tv_nsec);
    double time_total = time_nsec + time_sec;

    // byte * 1000 / nsec = mb / sec
    double mb_read_per_second = (double) (REPEAT*memory_size*1000 / (time_total));
    printf("MB read per second : %f\n", mb_read_per_second);
    free(small_array);
}

double wirteTime(int* A, size_t counter) {
	double start = 0;
	double end = 0;
	int i = 0;
	int j = 0;
	// int ofset = Offset;

	double total_time = 0;
    struct timespec read_start,read_end;
	clock_gettime(CLOCK_REALTIME,&read_start);
	while(j < REPEAT)
	{
		j++;
		for (size_t k = 0; k < counter; k++){
			A[k] = 0;
		}
		
	}
	clock_gettime(CLOCK_REALTIME,&read_end);
	total_time = (read_end.tv_sec - read_start.tv_sec) * 1e9;
	total_time += (read_end.tv_nsec - read_start.tv_nsec);
	double cost = counter * REPEAT;
	printf("%f\n", 4*cost*1000 / total_time);
	// printf("%lu\n", (unsigned long)(4 * counter * loops));
	return (cost*1000 / total_time);
}

double readTime(int* A, size_t counter){
    unsigned int stride = 1 << 10;
    size_t j = 0;
    int a;
    struct timespec read_start,read_end;
    double total_time = 0;
	clock_gettime(CLOCK_REALTIME,&read_start);
    while (j < REPEAT){
        j++;
        for (size_t k=0; k<counter;k++){
            a = A[k];
            a += 1;
        }
    }
    clock_gettime(CLOCK_REALTIME, &read_end);
    total_time = (read_end.tv_sec - read_start.tv_sec) * 1e9;
	total_time += (read_end.tv_nsec - read_start.tv_nsec);
	double cost = counter * REPEAT;
	printf("%f\n", 4*cost*1000 / total_time);
	// printf("%lu\n", (unsigned long)(4 * counter * loops));
	return (cost*1000 / total_time);
}


int main(){
    size_t counter = 1 << 26;
	
	int *A = (int *)malloc(counter * sizeof(int));
	for (int j = 0; j < counter; ++j)
	{
		A[j] = 0;
	}
   
    wirteTime(A, counter);
    int *B  = (int *)malloc(counter * sizeof(int));
	for (int j = 0; j < counter; ++j)
	{
		B[j] = 0;
	}
    readTime(A, counter);
    return 0;
}