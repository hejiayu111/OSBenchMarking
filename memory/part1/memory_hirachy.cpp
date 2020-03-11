#include <stdio.h>
#include <stdlib.h>
#include "rdtsc.h"
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char* argv[]) {

    struct timespec read_start,read_end;

    unsigned long long start, end;
    double doubletotal;
    srand(time(NULL));
    unsigned int stride = 2048;

    int size = 1;
    unsigned int loops = 1000000;
    int *arrayDirt = (int*)malloc(sizeof(int)* (1 << 27));

    double clock_overhead;
    clock_gettime(CLOCK_REALTIME, &read_start);
    clock_gettime(CLOCK_REALTIME, &read_end);
    clock_overhead = (read_end.tv_sec - read_start.tv_sec)*1e9;
    clock_overhead += (read_end.tv_nsec - read_start.tv_nsec);

    for(;size < 27;size++) {
        unsigned int arraysize = 1 << size;
        int i = 0;
        int *array = (int*)malloc( sizeof(int) * arraysize);
        // memset(array,'a',arraysize);
        for (int j = 0; j < arraysize;j++){
            array[j] = (j + stride) % arraysize;
        }
        for (int j =0; j < 1 << 27 ; j++){
            arrayDirt[j] = 1;
        }
        int idx = rand() % arraysize;
        clock_gettime(CLOCK_REALTIME, &read_start);
        for(;i < loops;i++) {
            idx = array[idx];
        }
        clock_gettime(CLOCK_REALTIME, &read_end);
        
        doubletotal += (read_end.tv_sec - read_start.tv_sec)*1e9;
        doubletotal += (read_end.tv_nsec - read_start.tv_nsec);

        doubletotal = (doubletotal-clock_overhead) / loops;  
        
        free(array);
        
        
        printf("array size : %d, stride : %d ,RAM access time : %f ns\n", size, stride,doubletotal);
        
        //sleep(1);
    }
    
    
    
    return 0;
    
}

