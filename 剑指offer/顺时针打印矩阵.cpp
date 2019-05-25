//
// Created by zhao on 19-5-25.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        if (matrix.empty()) return {};
        int m=matrix.size(),n=matrix[0].size();
        vector<int> res(m*n);
        int pos=0;
        int up=0,down=m-1,left=0,right=n-1;
        while(1)
        {
            for(int col=left;col<=right;++col) {res[pos]=matrix[up][col]; ++pos;}
            if(++up>down) break;
            for(int row=up;row<=down;++row) {res[pos]=matrix[row][right]; ++pos;}
            if(--right<left) break;
            for(int col=right;col>=left;--col) {res[pos]=matrix[down][col]; ++pos;}
            if(--down<up) break;
            for(int row=down;row>=up;--row) {res[pos]=matrix[row][left];++pos;}
            if(++left>right) break;
        }
        return res;
    }
};