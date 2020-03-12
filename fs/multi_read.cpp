#include "MyFile.hpp"
#include "rdtsc.h"
#include <stdlib.h>
#include <iostream> 
#include <unistd.h> 


void MyFile::file_multi_read(){
	int n = 8;
	for (int i = 0; i < n; i++){
		int child = fork();
		if (child < 0){
			abort();
		}else if (child == 0){
			MyFile::fread_rand();
			cout << "\nCurrent Process's number is : " 
             << getpid() << endl;
			exit(0);
		}
	}
}
