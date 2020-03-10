#include <cstdlib>

#include "MyFile.hpp"

void MyFile::measure_cache(){
    char file_name_buffer[20]; 
    void* buffer = malloc(FILE_BLOCK);
    size_t block_num;
    struct timespec read_start,read_end;
    double time_total = 0;
    double time_sec = 0; 
    double time_nsec = 0; 

    std::cout << "===========================measuring cache================" << std::endl;
    for (int i = 0; i < FILES_NUM; i++){
        sprintf(file_name_buffer, "./big_file_%d.txt", i);
        int f = open(file_name_buffer, O_RDONLY | O_SYNC);
        block_num = sizes[i] / FILE_BLOCK;
        // put everything to cache if possible
        for (size_t j = 0; j < block_num;j++){
            lseek(f, j*FILE_BLOCK, SEEK_SET);
            read(f, buffer, FILE_BLOCK);
        }
        close(f);

        f = open(file_name_buffer, O_RDONLY | O_SYNC);
        time_total = 0;
        time_nsec = 0;
        time_sec = 0;
        for (size_t j =0; j < block_num;j++){
            lseek(f, j*FILE_BLOCK, SEEK_SET);
            clock_gettime(CLOCK_REALTIME, &read_start);
            read(f, buffer, FILE_BLOCK);
            clock_gettime(CLOCK_REALTIME, &read_end);
            time_sec = (read_end.tv_sec * 1e9 - read_start.tv_sec * 1e9);
            time_nsec = (read_end.tv_nsec - read_start.tv_nsec);
            time_total += time_sec + time_nsec;
        }
        close(f);
        std::cout << sizes_string[i] << " " << "read time is " <<(double)time_total/block_num << std::endl;
    }
    free(buffer);
    std::cout<< "===================cache measurment finished=====================" << std::endl;
}