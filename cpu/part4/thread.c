#include "rdtsc.h"
#include "stdlib.h"
#include "stdio.h"
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>

#define RDTSC_TIME 120
#define ITER_TIME 6
#define LOOP 1000

void *func(void *arg) {
    pthread_exit(NULL);
}

int main() {
    unsigned long long total = 0;
    int i = 0;
    unsigned long long start, end;
    for (; i < LOOP; i++) {        
        pthread_t thread;
        start = rdtsc();
        pthread_create(&thread, NULL, func, NULL);
        end = rdtsc();
        total += (end - start - RDTSC_TIME - ITER_TIME);
        pthread_join(thread, NULL);
    }
    printf("pthread creation time is : %f cycles; Total : %llu \n", total*1.0/LOOP, total);

    return 0;
}
