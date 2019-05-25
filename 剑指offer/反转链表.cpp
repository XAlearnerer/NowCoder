//
// Created by zhao on 19-5-25.
//

#include <iostream>
#include <vector>

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
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* res=NULL;
        while(pHead)
        {
            ListNode* post=pHead->next;
            pHead->next=res;
            res=pHead;
            pHead=post;
        }

        return res;
    }
};