echo "disabling hardware prefetching"
sudo modprobe msr
sudo wrmsr -a 0x1a4 0xf
g++ -I../../ memory_hirachy.cpp
./a.out
echo "enable hardware prefetchig"
sudo wrmsr -a 0x1a4 0x0
echo "expreiment finished"
