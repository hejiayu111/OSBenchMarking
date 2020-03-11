#include "rdtsc.h"

#include <unistd.h>
#include <sys/mman.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define LOOP 100
static unsigned long long* total; 

int main() {  
    total = mmap(NULL, sizeof *total, PROT_READ | PROT_WRITE, 
                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    *total = 0;
    unsigned long long start, end;
    int i = 0;
    
    for (; i < LOOP; i++) {
        pid_t pid = fork();  
        if (pid == 0) {
            start = rdtsc();
            getpid();
            end = rdtsc();
            *total += end - start;
            return 0;
        }
         
        else {
            wait(NULL);
        }
    }
    printf("average system call time is : %f\n", *total*1.0/LOOP);
    return 0;
}

