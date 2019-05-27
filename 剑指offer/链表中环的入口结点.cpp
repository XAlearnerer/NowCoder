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
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		ListNode* fast = pHead;
		ListNode* slow = pHead;

		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)
			{
				ListNode* a = pHead;
				ListNode* b = fast;
				while (a != b)
				{
					a = a->next;
					b = b->next;
				}
				return a;
			}
		}

		return NULL;
	}
};
