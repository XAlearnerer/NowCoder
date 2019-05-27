
#include<iostream>

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
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		if (!pHead1 || !pHead2) return nullptr;
		int len1 = 1, len2 = 1;
		ListNode* b1 = pHead1, *b2 = pHead2;
		while (b1->next)
		{
			b1 = b1->next;
			++len1;
		}
		while (b2->next)
		{
			b2 = b2->next;
			++len2;
		}
		
		if (b1 != b2) return nullptr;

		if (len1 > len2)
		{
			int dif = len1 - len2;
			while (dif)
			{
				pHead1 = pHead1->next;
				--dif;
			}
		}
		else
		{
			int dif = len2 - len1;
			while (dif)
			{
				pHead2 = pHead2->next;
				--dif;
			}
		}

		while (pHead1 && pHead2 && pHead1->val != pHead2->val)
		{
			pHead1 = pHead1->next;
			pHead2 = pHead2->next;
		}
		if (pHead1->val == pHead2->val) return pHead1;
		else return NULL;
	}
};