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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(!pRoot1 || !pRoot2) return false;
        if(helper(pRoot1,pRoot2)) return true;
        return HasSubtree(pRoot1->left,pRoot2) || HasSubtree(pRoot1->right,pRoot2);
    }

    bool helper(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(!pRoot2) return true;
    ///////////////////////

    // 之前漏掉这句
        if(!pRoot1) return false;

    ///////////////////////
        if(pRoot1->val==pRoot2->val) return helper(pRoot1->left,pRoot2->left)
            && helper(pRoot1->right,pRoot2->right);
        return false;
    }
};
