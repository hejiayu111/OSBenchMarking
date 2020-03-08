#include <iostream>
#include <fstream>
#include <stdio.h>
#include <unistd.h> 
#include <sys/types.h> 
#include <fcntl.h> 
#include <stdlib.h>
#include <malloc.h>
#include <string>

#ifndef MY_FILE_HPP
#define MY_FILE_HPP

#define FILE_BLOCK ((size_t)(4096))
#define MB ((size_t)(1024*1024))
#define GB ((size_t)(1024*1024*1024))
#define FILES_NUM 13

class MyFile{
    private:
        size_t sizes[FILES_NUM] = {32*MB, 64*MB, 128*MB, 
        256*MB, 512*MB, 1*GB, 2*GB, 3*GB, 4*GB, 5*GB, 6*GB, 7*GB, 8*GB};

        std::string sizes_string[FILES_NUM] = {"32MB", "64MB", "128MB", "256MB",
        "512MB", "1GB", "2GB", "3GB", "4GB", "5GB", "6GB", "7GB", "8GB"};
    public:
        void measure_cache();
        void fread_seq();
        void fread_rand();
        void file_create();
};


#endif