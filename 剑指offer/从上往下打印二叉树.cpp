//
// Created by zhao on 19-5-26.
//

#include <iostream>
#include <vector>
#include <queue>

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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode* >q;
        if(!root) return {};
        q.push(root);
        vector<int> res;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;++i)
            {
                auto f=q.front();
                q.pop();
                res.push_back(f->val);
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
        }

        return res;
    }
};
