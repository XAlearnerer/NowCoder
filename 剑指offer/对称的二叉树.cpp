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
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (!pRoot) return true;
		return helper(pRoot->left, pRoot->right);
	}

	bool helper(TreeNode* left, TreeNode* right)
	{
		if (!left && !right) return true;
		if ((left && !right) || (!left && right) || (left->val != right->val)) return false;
		return helper(left->left, right->right) && helper(left->right, right->left);
	}

};