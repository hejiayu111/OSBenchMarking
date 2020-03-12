# g++ file_create.cpp measure_cache.cpp main.cpp fread_rand.cpp fread_seq.cpp -o a.cout
# g++ file_create.cpp measure_cache.cpp main_fread.cpp fread_rand.cpp fread_seq.cpp -o b.out
g++ -I../ file_create.cpp measure_cache.cpp multi_read.cpp fread_rand.cpp fread_seq.cpp main_fread.cpp -o multi_read.out
# nocache ./b.out