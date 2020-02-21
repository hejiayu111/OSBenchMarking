#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "rdtsc.h"
#include <unistd.h>
void page_fault_service() {
    printf("get 0\n");
    double average_cycles = 0;
    
    int f = open("bible.txt",O_RDWR |O_CREAT);
    if (f < 0) {
        printf("Error while opening file.\n");
        exit(-1);
    }
    int step = 4096*2; 
    printf("get 1\n");
    int file_size = 4* 1024 * 900; 
    int iterations = file_size / step;
    char* map =(char*) mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, f, 0);
    printf("get 2\n");
    volatile char value = 0;
    unsigned long start = rdtsc();
    for (int i = 0; i < iterations; i++) {
        map[i * step] = 'a';
        // value = map[i*step];
    }
    unsigned long end = rdtsc();
    double res = 1.0 * (end - start) / iterations;
    if (munmap(map, file_size) == -1) {
        printf("Error when munmap.\n");
        exit(-1);
    }
    close(f);
    printf("average cycles is %g\n", res);
}

int main(){
    page_fault_service();
    return 0;
}

