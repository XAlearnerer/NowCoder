//
// Created by zhao on 19-5-23.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty()) return 0;
        int left=0,right=rotateArray.size()-1;
        while(left<right)
        {
            if(rotateArray[left]<rotateArray[right]) break;
            int mid=left+(right-left)/2;
            if(rotateArray[mid]<rotateArray[left])
            {
                right=mid;
            }
            else
                left=mid+1;
        }

        return rotateArray[left];
    }
};