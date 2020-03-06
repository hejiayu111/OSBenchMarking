#include <iostream>
#include <fstream>
#include <stdio.h>
#include <unistd.h> 
#include <sys/types.h> 
#include <fcntl.h> 

#ifndef MY_FILE_HPP
#define MY_FILE_HPP

#define FILE_BLOCK ((size_t)(4096))
#define MB ((size_t)(1024*1024))
#define GB ((size_t)(1024*1024*1024))

class MyFile{
    private:
        size_t sizes[10] = {32*MB, 64*MB, 128*MB, 
        256*MB, 512*MB, 1*GB, 2*GB, 4*GB, 8*GB, 16*GB};
    public:
        void measure_cache();
        // void fread_seq();
        // void fread_rand();
        void file_create();
};


#endif