//
// Created by zhao on 19-5-25.
//


#include <iostream>
#include <vector>

using namespace std;


////// exponent 可能为负数！！！！
class Solution {
public:
    double Power(double base, int exponent)
    {
        if(exponent==0) return 1;
        else if(exponent > 0) return helper1(base,exponent);
        else return helper2(base,exponent);
    }

    double helper1(double base, int exponent)
    {
        if(exponent==0) return 1;
        if(exponent % 2==0) {
            double cur = helper1(base, exponent / 2);
            return cur*cur;
        }
        else
        {
            double cur = helper1(base, exponent / 2);
            return cur*cur*base;
        }
    }

    double helper2(double base, int exponent)
    {
        if(exponent==0) return 1;
        if(exponent % 2==0) {
            double cur = helper1(base, exponent / 2);
            return 1/(cur*cur);
        }
        else
        {
            double cur = helper1(base, exponent / 2);
            return 1/(cur*cur*base);
        }

    }
};

