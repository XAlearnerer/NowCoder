//
// Created by zhao on 19-5-26.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> s;
        int pos=0;
        for(int i=0;i<pushV.size();++i)
        {
            if(s.empty()) {s.push(pushV[i]); continue; }
            if(s.top()==popV[pos])
            {
                s.pop();
                ++pos;
                --i;
            }
            else
            {
                s.push(pushV[i]);
            }
        }


        while(pos<popV.size())
        {
            if(s.top()==popV[pos])
            {
                s.pop();
                ++pos;
            }
            else return false;
        }

        return true;
    }
};
