#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main(){
    //printf("get 0\n"); 
    struct timespec overhead_start, overhead_end;
    clock_gettime(CLOCK_REALTIME,&overhead_start);
    clock_gettime(CLOCK_REALTIME,&overhead_end);
    double overhead_time_sec = (overhead_end.tv_sec * 1e9 - overhead_start.tv_sec * 1e9);
    double overhead_time_nsec = (overhead_end.tv_nsec - overhead_start.tv_nsec);
    double overhead_time_total = overhead_time_sec + overhead_time_nsec;

    int f = open("bible.txt",O_RDWR |O_CREAT);
    if (f < 0) {
        printf("Error while opening file.\n");
        return 0;
    }
    int step = 4096 * 2; 
    //printf("get 1\n");
    int file_size = 4 * 1024 * 900; 
    int iterations = file_size / step;
    char* map =(char*) mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, f, 0);
    //printf("get 2\n");

    struct timespec time_start, time_end;
    clock_gettime(CLOCK_REALTIME,&time_start);
    for (int i = 0; i < iterations; i++) {
        map[i * step] = 'a';
    }
    clock_gettime(CLOCK_REALTIME,&time_end);
    double time_sec = (time_end.tv_sec * 1e9 - time_start.tv_sec * 1e9);
    double time_nsec = (time_end.tv_nsec - time_start.tv_nsec);
    double time_total = time_sec + time_nsec;

    double res = 1.0 * (time_total - overhead_time_total) / iterations;
    if (munmap(map, file_size) == -1) {
        printf("Error when munmap!\n");
        return 0;
    }
    close(f);
    printf("page fault average time is %f ns\n", res);
    return 0;
}

