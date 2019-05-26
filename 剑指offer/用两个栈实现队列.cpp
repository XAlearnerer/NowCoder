//
// Created by zhao on 19-5-26.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    void push(int node) {
        while(!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        stack1.push(node);
        while(!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }

    }

    int pop() {
        int t=stack1.top();
        stack1.pop();
        return t;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};