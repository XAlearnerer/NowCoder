//
// Created by zhao on 19-5-25.
//


#include <iostream>
#include <vector>

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
    void Mirror(TreeNode *pRoot) {
        helper(pRoot);
    }

    TreeNode* helper(TreeNode*& root)
    {
        if(!root) return root;
        TreeNode* cur=root->left;
        root->left=helper(root->right);
        root->right=helper(cur);
        return root;
    }

};