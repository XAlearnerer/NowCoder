//
// Created by zhao on 19-5-23.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty() || array[0].empty()) return 0;
        int n=array.size(),m=array[0].size();
        int i=n-1,j=0;
        while(i>=0 && j<m)
        {
            if(array[i][j]==target)
                return true;
            else if(target>array[i][j]) ++j;
            else --i;
        }
        return false;
    }
};