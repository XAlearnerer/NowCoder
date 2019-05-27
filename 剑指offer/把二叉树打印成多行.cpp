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
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int> > res;
		if (!pRoot) return res;
		queue<TreeNode*> q;
		q.push(pRoot);
		while (!q.empty())
		{
			vector<int> cur;
			int size = q.size();
			for (int i = 0; i < size; ++i)
			{
				auto f = q.front();
				q.pop();
				cur.push_back(f->val);
				if (f->left) q.push(f->left);
				if (f->right)q.push(f->right);
			}
			res.push_back(cur);
		}
		return res;
	}

};