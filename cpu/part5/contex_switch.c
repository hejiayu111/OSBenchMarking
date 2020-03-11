#include "rdtsc.h"
#include "stdlib.h"
#include "stdio.h"
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {
    
    int p[2];
    if (pipe(p)<0){
        exit(1);
    }
    unsigned long long start;
    unsigned long long end;
    if (fork() != 0){
        start = rdtsc();
        wait(NULL);
        read(p[0], &end, sizeof(unsigned long long));
    }
    else{
        end = rdtsc();
        write(p[1], &end, sizeof(unsigned long long));
        return 0;
    }
    
    printf("contex switch time is %llu\n", end - start);
    return 0;
}
