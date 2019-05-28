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
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.empty() || vin.empty()) return NULL;
		return helper(pre, vin, 0, pre.size() - 1, 0, vin.size() - 1);
	}

	TreeNode* helper(vector<int> pre, vector<int> vin, int pl, int pr, int vl, int vr)
	{
		if (pl > pr || vl > vr) return NULL;
		int mid = -1;
		for (mid = vl; mid <= vr; ++mid)
		{
			if (vin[mid] == pre[pl]) break;
		}
		TreeNode* root = new TreeNode(pre[pl]);
		root->left = helper(pre, vin, pl + 1, pl + mid - vl, vl, mid - 1);
		root->right = helper(pre, vin, pl + mid + 1 - vl, pr, mid + 1, vr);
		return root;
	}

};


