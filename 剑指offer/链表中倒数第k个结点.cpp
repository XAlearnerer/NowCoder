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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(!pListHead) return NULL;
        if(k<=0) return NULL;

        ListNode *a,*b;
        a=pListHead; b=pListHead;
        for(int i=1;i<k;++i)
        {
            if(b->next)
                b=b->next;
            else return NULL;
        }

        while(b->next)
        {
            a=a->next;
            b=b->next;
        }
        return a;
    }
};