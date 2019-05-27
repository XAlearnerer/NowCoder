#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

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
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		if (k == 0) return NULL;
		if (!pRoot) return 0;
		queue<TreeNode*> q;
		q.push(pRoot);
		vector<int> res;
		while (!q.empty())
		{
			int size = q.size();
			for (int i = 0; i < size; ++i)
			{
				auto f = q.front();
				res.push_back(f->val);
				q.pop();
				if (f->left) q.push(f->left);
				if (f->right)q.push(f->right);
			}
		}
	
		if (k > res.size()) return NULL;
		sort(res.begin(), res.end());
		return new TreeNode(res[k-1]);
	}
};