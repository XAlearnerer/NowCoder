#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if (!pRoot) return 0;
		int res = 0;
		queue<TreeNode*> q;
		q.push(pRoot);
		while (!q.empty())
		{
			int size = q.size();
			for (int i = 0; i < size; ++i)
			{
				auto f = q.front();
				q.pop();
				if (f->left) q.push(f->left);
				if (f->right)q.push(f->right);
			}
			++res;
		}
		return res;
	}
};