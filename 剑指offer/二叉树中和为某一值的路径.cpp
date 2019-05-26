#include<iostream>
#include<vector>
#include<stack>
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
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		if (!root) return {};
		vector<vector<int> > res;
		vector<int> cur; int k = 0;
		helper(root, expectNumber, res, cur, k);
		return res;
	}

	void helper(TreeNode* root, int expectNumber, vector<vector<int> >& res, vector<int>& cur, int& k)
	{
		cur.push_back(root->val);
		k += root->val;

		if (!root->left&& !root->right && k == expectNumber)
		{
			res.push_back(cur);
			return;
		}

		if (root->left) {
			helper(root->left, expectNumber, res, cur, k);
			cur.pop_back(); 
			k -= root->left->val;
		}
		if (root->right) {
			helper(root->right, expectNumber, res, cur, k);
			cur.pop_back(); 
			k -= root->right->val;
		}
	}
};

