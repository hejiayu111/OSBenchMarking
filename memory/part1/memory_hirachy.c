#include <stdio.h>
#include <stdlib.h>
#include "rdtsc.h"
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char* argv[]) {


    unsigned long long start, end;
    double doubletotal;
    srand(time(NULL));
    unsigned int stride = 2048;

    int size = 1;
    unsigned int loops = 1000000;
    int *arrayDirt = (int*)malloc(sizeof(int)* (1 << 27));


    for(;size < 27;size++) {
        unsigned int arraysize = 1 << size;
        int i = 0;
        int *array = (int*)malloc( sizeof(int) * arraysize);
        // memset(array,'a',arraysize);
        for (int j = 0; j < arraysize;j++){
            array[j] = (j+ stride) % arraysize;
        }
        for (int j =0; j < 1 << 27 ; j++){
            arrayDirt[j] = 1;
        }
        // unsigned int idx = rand()%arraysize;
        unsigned int idx = 0;
        start = rdtsc();
        for(;i < loops;i++) {
            idx = array[idx];
        }
        end = rdtsc();
        
        doubletotal += (double)(end- start) / loops;  
        
        free(array);
        
        
        printf("array size : %d, RAM access cycle : %f\n", size, doubletotal);
        
        //sleep(1);
    }
    
    
    
    return 0;
    
}

