#include "rdtsc.h"
#include "stdlib.h"
#include "stdio.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define LOOP 100
#define rdtsc_time 120

int main() {
    unsigned long long total = 0;
    unsigned long long start, end;
    int i = 0;
    
    for (; i < LOOP; i++) {
        start = rdtsc();
        pid_t pid = fork();

        if (pid == 0) {

            return 0;
        } 
        
        else {
            wait(NULL);
            end = rdtsc();
            total += (end - start - rdtsc_time);
        }
    }

    printf("process creation averagely takes %f cycles\n", 1.0 * total/LOOP);

    return 0;
}
