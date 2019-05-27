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

//class Solution {
//public:
//	ListNode* deleteDuplication(ListNode* pHead)
//	{
//		if (!pHead || !pHead->next) return pHead;
//		ListNode* a = pHead, *b = pHead->next;
//		ListNode* begin = pHead;
//		if (pHead->val == pHead->next->val)
//		{
//			while (a->val == b->val)
//				b = b->next;
//			begin = b;
//		}
//
//		a = begin, b = begin->next;
//		while (b)
//		{
//			if (b->val == b->next->val)
//			{
//				while (b->val == b->next->val) b = b->next;
//				if (b)
//				{
//					a->next = b;
//					a = b;
//					b = b->next;
//				}
//				else
//					a->next = NULL;
//			}
//			else
//			{
//				a = a->next;
//				b = b->next;
//			}
//		}
//		
//		return begin;
//	}
//};

class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (!pHead || !pHead->next) return pHead;
		ListNode *start = new ListNode(0);
		start->next = pHead;
		ListNode *pre = start;
		while (pre->next)
		{
			ListNode *cur = pre->next;
			while (cur->next && cur->next->val == cur->val) cur = cur->next;
			if (cur != pre->next) pre->next = cur->next;
			else pre = pre->next;
		}
		return start->next;
	}
};
