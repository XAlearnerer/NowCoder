#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<unordered_map>

using namespace std;


struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};

class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (!pHead) return pHead;
		RandomListNode* res = new RandomListNode(pHead->label);
		if (!pHead->next)
		{
			res->next = NULL;
			res->random = pHead->random;
			return res;
		}

		RandomListNode* be = res;
		unordered_map<RandomListNode*, RandomListNode*> m;
		m[pHead] = res;

		RandomListNode* cur = pHead->next;
		while (cur)
		{
			RandomListNode* t = new RandomListNode(cur->label);
			m[cur] = t;
			be->next = t;
			be = be->next;
			cur = cur->next;
		}

		RandomListNode* be2 = res;
		RandomListNode* tmp = pHead;
		while(be2)
		{
			be2->random = m[tmp->random];
			be2 = be2->next;
			tmp = tmp->next;
		}
		return res;
	}
};



class Solution2 {
public:
	RandomListNode *Clone(RandomListNode *pHead) {
		if (!pHead) return NULL;
		RandomListNode *res = new RandomListNode(pHead->label);
		RandomListNode *be = res;
		RandomListNode *cur = pHead->next;

		unordered_map<RandomListNode*, RandomListNode*> map;
		map[pHead] = res;
		while (cur) {
			RandomListNode *t = new RandomListNode(cur->label);
			be->next = t;
			map.insert(pair<RandomListNode*, RandomListNode*>(cur, t));
			be = be->next;
			cur = cur->next;
		}

		RandomListNode *be2 = res;
		RandomListNode *tmp = pHead;

		while (be2)
		{
			be2->random = map[tmp->random];
			be2 = be2->next;
			tmp = tmp->next;
		}

		return res;
	}
};