#include "MyFile.hpp"
#include <cstdlib>

void MyFile::fread_seq(){
    char file_name_buffer[20]; 
    void* buffer = aligned_alloc(FILE_BLOCK, FILE_BLOCK);
    size_t block_num;
    struct timespec read_start,read_end;
    time_t time_total = 0;
    time_t time_sec = 0; 
    time_t time_nsec = 0; 
    for (int i = 0; i < FILES_NUM; i++){
        sprintf(file_name_buffer, "./big_file_%d.txt", i);
        int f = open(file_name_buffer, O_RDONLY | O_SYNC | O_DIRECT);
        block_num = sizes[i] / FILE_BLOCK;
        for (size_t j =0; j < block_num;j++){
            clock_gettime(CLOCK_REALTIME, &read_start);
            read(f, buffer, FILE_BLOCK);
            clock_gettime(CLOCK_REALTIME, &read_end);
            time_sec = (read_end.tv_sec * 1e9 - read_start.tv_sec * 1e9);
            time_nsec = (read_end.tv_nsec - read_start.tv_nsec);
            time_total += time_sec + time_nsec;
        }
        close(f);
        std::cout << sizes_string[i] << " " << "sequential read time is " <<(double)time_total/block_num << std::endl;
    }
    free(buffer);
}