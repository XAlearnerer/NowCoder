#include<vector>
#include<iostream>
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
	bool IsBalanced_Solution(TreeNode* pRoot) {
		if (!pRoot) return true;
		int left = helper(pRoot->left);
		int right = helper(pRoot->right);
		if (abs(left - right) > 1) return false;
		if (pRoot->left && pRoot->right) return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
		return true;
		
	}

	//bool helper(TreeNode* root)
	//{
	//	if (!root->left && !root->right) return true;
	//	else if (root->left && root->right) return helper(root->left) && helper(root->right);
	//	else if (root->left)
	//	{
	//		if (!root->left->left && !root->left->right) return true;
	//		else return false;
	//	}
	//	else 
	//	{
	//		if (!root->right->left && !root->right->right) return true;
	//		else return false;
	//	}
	//}

	int helper(TreeNode* pRoot)
	{
		if (!pRoot) return 0;
		int left = helper(pRoot->left);
		int right = helper(pRoot->right);

		if (left < right) return right + 1;
		else return left + 1;
	}

};

