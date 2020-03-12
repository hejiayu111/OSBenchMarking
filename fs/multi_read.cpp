#include "MyFile.hpp"
#include "rdtsc.h"
#include <stdlib.h>

void MyFile::readFile(int i){
	char file_name_buffer[20];
	unsigned long sum = 0;
	void* buffer = malloc(FILE_BLOCK);
	sprintf(file_name_buffer, "./big_file_%d.txt", i);
	int fd = open(file_name_buffer, O_RDONLY | O_SYNC);
	
	unsigned start, end;
	int count = 0;
	while(true)
	{
		start = rdtsc();
		ssize_t bytes = read(fd, buffer, FILE_BLOCK);
		end = rdtsc();
		if(bytes <= 0)
			break;
		sum += (end - start);
		count++;
	}
	printf("The average time for reading in process %d is %f cpu cycles\n", i, (double)(sum) / (double)(count));
}


void MyFile::file_multi_read(){
	int n = 16;
	for (int i = 0; i < n; i++){
		int child = fork();
		if (child < 0){
			abort();
		}else if (child == 0){
			MyFile::readFile(i);
			exit(0);
		}
	}
}