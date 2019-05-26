#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
/*		if (!pRootOfTree) return nullptr;

		TreeNode* list = new TreeNode(-1);
		TreeNode* res = list;

// 对应输出应该为:
// 	From left to right are : 4, 6, 8, 10, 12, 14, 16; 
// 	From right to left are : 16, 14, 12, 10, 8, 6, 4;
// 你的输出为:
// 	From left to right are : 4, 6, 8, 10, 12, 14, 16;
// 	From right to left are : 16, 14, 12, 10, 8, 6, 4, -1;

		helper(pRootOfTree, list);
		return res->right;

*/
		if (!pRootOfTree) return nullptr;
		TreeNode* list = nullptr;
		helper(pRootOfTree, list);
		TreeNode* res = pRootOfTree;
		while (res->left)
			res = res->left;
		return res;

	}

	void helper(TreeNode* root, TreeNode*& list)
	{
		if (!root) return;
		helper(root->left, list);


		root->left = list;
		if (list) list->right = root;
		list = root;


		helper(root->right, list);
	}
};