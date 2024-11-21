
import os
tc = 0
os.system("g++ std.cpp -o std.exe")
os.system("g++ solve.cpp -o solve.exe")

while True:
    os.system("python data.py > data.in")
    os.system("std.exe < data.in > std.out")
    os.system("solve.exe < data.in > solve.out"); 
    if(os.system("fc std.out solve.out")):
        print("WA")
        exit(0)
    else:
        tc += 1
        print("AC #%d" %(tc))