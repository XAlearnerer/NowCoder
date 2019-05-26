//
// Created by zhao on 19-5-26.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int rectCover(int number) {
        if(number==0) return 0;
        if(number==1) return 1;
        if(number==2) return 2;
        int a=1,b=2; int c=3;
        for(int i=3;i<=number;++i)
        {
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};
