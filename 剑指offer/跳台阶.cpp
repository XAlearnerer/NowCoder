//
// Created by zhao on 19-5-24.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jumpFloor(int number) {
        if(number==0) return 0;
        if(number==1) return 1;
        vector<int> dp(number+1,0);
        dp[1]=1,dp[2]=2;
        for(int i=3;i<=number;++i)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[number];
    }
};
