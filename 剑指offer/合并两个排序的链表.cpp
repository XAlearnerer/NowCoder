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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* res=new ListNode(-1);
        ListNode* b=res;
        while(pHead1 && pHead2)
        {
            //res->next= pHead1->val>pHead2->val?pHead2:pHead1;
            if(pHead1->val<pHead2->val)
            {
                res->next=pHead1;
                pHead1=pHead1->next;
            }
            else
            {
                res->next=pHead2;
                pHead2=pHead2->next;
            }
            res=res->next;
        }
//        while(pHead1)
//        {
//            res->next=pHead1;
//            res=res->next;
//            pHead1=pHead1->next;
//        }
//        while(pHead2)
//        {
//            res->next=pHead2;
//            res=res->next;
//            pHead2=pHead2->next;
//        }
        if(pHead1) res->next=pHead1;
        if(pHead2) res->next=pHead2;
        return b->next;
    }
};
