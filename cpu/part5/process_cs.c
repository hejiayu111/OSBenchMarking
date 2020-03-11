#include "rdtsc.h"
#include "stdlib.h"
#include "stdio.h"
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>

#define LOOP 100

int main(int argc, char **argv) {
    unsigned long long total = 0;
    
    int i = 0;

    for (; i < loops; i++) {
        unsigned long long start, end;
        
        long p;
        pthread_t thread;
        start = rdtsc();
        pthread_create(&thread, NULL, func, (void *)p);
        end = rdtsc();
        total += (end - start);
        
        pthread_join(thread, NULL);
    }


    printf("pthread task creation : %llu cycles; Total : %llu \n", total/loops, total);

    return 0;
}
