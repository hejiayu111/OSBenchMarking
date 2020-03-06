#include "MyFile.hpp"
using namespace std;

void MyFile::file_create(){
    char buffer[20]; 
    ofstream file;
    for (int i = 0; i < 10; i++){
        size_t size = sizes[i];
        sprintf(buffer, "big_file_%d.txt", i);
        file.open(buffer);
        for (size_t j =0; j < size; j++){    
            unsigned char c = rand() % 128;
            file << c;
            // cout << c << endl;
        }
        file.close();
    }
}
