//
// Created by zhao on 19-5-24.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int Fibonacci(int n) {
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        //return Fibonacci(n-1)+Fibonacci(n-2);
        int a=1,b=1;
        int c=2;
        for(int i=2;i<n;++i)
        {
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};
