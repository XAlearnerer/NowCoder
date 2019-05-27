#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode->right)
		{
			TreeLinkNode* cur = pNode->right;
			while (cur->left)
			{
				cur = cur->left;
			}
			return cur;
		}
		else
		{
			if (!pNode->next) return NULL;
			TreeLinkNode* cur = pNode->next;
			if (cur->left == pNode) return cur;
			if (!cur->next) return NULL;
			else
			{
				TreeLinkNode* post = cur->next;
				if (post->left == cur) return post;
				else return NULL;
			}
		}
	}
};