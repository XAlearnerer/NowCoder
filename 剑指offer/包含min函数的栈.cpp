//
// Created by zhao on 19-5-25.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <limits.h>

using namespace std;

class Solution {
public:
    Solution():m(INT_MAX){}

    void push(int value) {
        if(value<=m)
        {
            s.push(m);
            m=value;
        }
        s.push(value);
    }
    void pop() {
        int t=s.top();
        s.pop();
        if(t==m)
        {
            m=s.top();
            s.pop();
        }

    }
    int top() {
        return s.top();
    }
    int min() {
        return m;
    }

    stack<int> s;
    int m;
};