#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "rdtsc.h"
#include <pthread.h>
#include <sched.h>

#define LOOP 100
#define _GNU_SOURCE
#define rdtsc_time 120

int p[2];

void *func(void *arg) {
    unsigned long long end = rdtsc();
    write(p[1], &end, sizeof(end));
    pthread_exit(NULL);
}

int main() {
    unsigned long long total = 0;
    unsigned long long start, end;
    int i = 0;
    pipe(p);
    pthread_t p_thread;
    int valid_loop = 0;
    
    for(; i < LOOP; i++) {
        pthread_create(&p_thread, NULL, func, NULL);
        start = rdtsc();
        sched_yield();
        read(p[0], &end, sizeof(end));
        total += (end - start - rdtsc_time);
        valid_loop += 1;
        pthread_join(p_thread, NULL);
    }
    
    printf("thread context switch time: %f cycles\n", 1.0 * total / LOOP);
    return 0;
}