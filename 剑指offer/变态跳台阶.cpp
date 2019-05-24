//
// Created by zhao on 19-5-24.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jumpFloorII(int number) {
        if(number==0) return 0;
        if(number==1) return 1;
        vector<int> dp(number+1,0);
        dp[1]=1,dp[2]=2;
        for(int i=3;i<=number;++i)
        {
            for(int j=i-1;j>0;--j)
            {
                dp[i]+=dp[i-j];
            }
            ++dp[i];
        }
        return dp[number];
    }
};
