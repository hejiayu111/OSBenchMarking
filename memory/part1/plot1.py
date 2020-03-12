import matplotlib.pyplot as plt

x = []
for i in range(1, 27):
    x.append(i)
y128, y256, y512, y1024, y2048 = [], [], [], [], []
with open("128.txt") as f:
    lines = f.readlines()
    for line in lines:
        line = line.rstrip('\n')
        words = line.split(' ')
        y128.append(float(words[-2]))

with open("256.txt") as f:
    lines = f.readlines()
    for line in lines:
        line = line.rstrip('\n')
        words = line.split(' ')
        y256.append(float(words[-2]))

with open("512.txt") as f:
    lines = f.readlines()
    for line in lines:
        line = line.rstrip('\n')
        words = line.split(' ')
        y512.append(float(words[-2]))

with open("1024.txt") as f:
    lines = f.readlines()
    for line in lines:
        line = line.rstrip('\n')
        words = line.split(' ')
        y1024.append(float(words[-2]))

with open("2048.txt") as f:
    lines = f.readlines()
    for line in lines:
        line = line.rstrip('\n')
        words = line.split(' ')
        y2048.append(float(words[-2]))

my_x_ticks = [i for i in range(1, 27)]
plt.figure(figsize=(8,6))
plt.plot(x,y128,label="stride 128")
plt.plot(x,y256,label="stride 256")
plt.plot(x,y512,label="stride 512")
plt.plot(x,y1024,label="stride 1024")
plt.plot(x,y2048,label="stride 2048")
plt.xticks(my_x_ticks)
plt.xlabel("Array size(log2)")
plt.ylabel("Latency(ns)")
plt.legend(loc = "best")
# plt.show()
plt.savefig('project2latency_new.png')


