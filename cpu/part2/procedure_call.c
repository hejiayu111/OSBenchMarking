#include "rdtsc.h"
#include "stdlib.h"
#include "stdio.h"

#define LOOP 1000000

void function0() {}
void function1(int arg1) {}
void function2(int arg1, int arg2) {}
void function3(int arg1, int arg2, int arg3) {}
void function4(int arg1, int arg2, int arg3, int arg4) {}
void function5(int arg1, int arg2, int arg3, int arg4, int arg5) {}
void function6(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6) {}
void function7(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7) {}


void meaure0() {
    int i = 0;
    unsigned long long total = 0;
    unsigned long long start, end;
    start = rdtsc();
    for(; i < LOOP; i++) {
        function0();
    }
    end = rdtsc();
    total = end - start;
    printf("overhead of 0 argument function is: %f cycles; Total : %llu \n", total*1.0/LOOP, total);
}

void measure1() {
    int i = 0;
    unsigned long long total = 0;
    unsigned long long start, end;
    int a;
    start = rdtsc();
    for(; i < LOOP; i++) {
        function1(a);
    }
    end = rdtsc();
    total = end - start;
    printf("overhead of 1 argument function is: %f cycles; Total : %llu \n", total*1.0/LOOP, total);
}

void measure2() {
    int i = 0;
    unsigned long long total = 0;
    unsigned long long start, end;
    int a,b;
    start = rdtsc();
    for(; i < LOOP; i++) {
        function2(a,b);
    }
    end = rdtsc();
    total = end - start;
    printf("overhead of 2 arguments function is: %f cycles; Total : %llu \n", total*1.0/LOOP, total);
}

void measure3() {
    int i = 0;
    unsigned long long total = 0;
    unsigned long long start, end;
    int a,b,c;
    start = rdtsc();
    for(; i < LOOP; i++) {
        function3(a,b,c);
    }
    end = rdtsc();
    total = end - start;
    printf("overhead of 3 arguments function is: %f cycles; Total : %llu \n", total*1.0/LOOP, total);
}

void measure4() {
    int i = 0;
    unsigned long long total = 0;
    unsigned long long start, end;
    int a,b,c,d;
    start = rdtsc();
    for(; i < LOOP; i++) {
        function4(a,b,c,d);
    }
    end = rdtsc();
    total = end - start;
    printf("overhead of 4 arguments function is: %f cycles; Total : %llu \n", total*1.0/LOOP, total);
}

void measure5() {
    int i = 0;
    unsigned long long total = 0;
    unsigned long long start, end;
    int a,b,c,d,e;
    start = rdtsc();
    for(; i < LOOP; i++) {
        function5(a,b,c,d,e);
    }
    end = rdtsc();
    total = end - start;
    printf("overhead of 5 argument function is: %f cycles; Total : %llu \n", total*1.0/LOOP, total);
}

void measure6() {
    int i = 0;
    unsigned long long total = 0;
    unsigned long long start, end;
    int a,b,c,d,e,f;
    start = rdtsc();
    for(; i < LOOP; i++) {
        function6(a,b,c,d,e,f);
    }
    end = rdtsc();
    total = end - start;
    printf("overhead of 6 argument function is: %f cycles; Total : %llu \n", total*1.0/LOOP, total);
}


void measure7() {
    int i = 0;
    unsigned long long total = 0;
    unsigned long long start, end;
    int a,b,c,d,e,f,g;
    start = rdtsc();
    for(; i < LOOP; i++) {
        function7(a,b,c,d,e,f,g);
    }
    end = rdtsc();
    total = end - start;
    printf("overhead of 7 argument function is: %f cycles; Total : %llu \n", total*1.0/LOOP, total);
}
    
int main() {
    meaure0();
    measure1();
    measure2();
    measure3();
    measure4();
    measure5();
    measure6();
    measure7();

    return 0;
}
