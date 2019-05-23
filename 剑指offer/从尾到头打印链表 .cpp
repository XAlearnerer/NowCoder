//
// Created by zhao on 19-5-23.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 struct ListNode {
       int val;
       struct ListNode *next;
       ListNode(int x) :
             val(x), next(NULL) {
       }
 };



class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        while(head)
        {
            res.push_back(head->val);
            head=head->next;
        }
        reverse(res.begin(),res.end());
        return res;

    }
};