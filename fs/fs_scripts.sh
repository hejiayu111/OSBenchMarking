g++ file_create.cpp measure_cache.cpp main.cpp fread_rand.cpp fread_seq.cpp -o a.cout
g++ file_create.cpp measure_cache.cpp main_fread.cpp fread_rand.cpp fread_seq.cpp -o b.out
nocache ./b.out