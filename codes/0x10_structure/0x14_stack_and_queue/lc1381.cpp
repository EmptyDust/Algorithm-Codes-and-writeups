#include <bits/stdc++.h>
using namespace std;

class CustomStack {
public:
    int v[1005];
    int i=0;
    int maxSize;
    CustomStack(int maxSize) {
        this->maxSize=maxSize;
    }
    
    void push(int x) {
        if(i<maxSize)
        v[i++]=x;
    }
    
    int pop() {
        return (i>0?v[--i]:-1);
    }
    
    void increment(int k, int val) {
        for(int j=0;j<min(k,i);++j)
            v[j]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */