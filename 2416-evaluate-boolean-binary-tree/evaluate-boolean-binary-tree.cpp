/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool rec(TreeNode * root)
    {
        if(root->val==3) 
        {
            return rec(root->left)&& rec(root->right);
        }
        else if(root->val==2)
        {
            return rec(root->left)|| rec(root->right);
        }
        return root->val;
    }
    bool evaluateTree(TreeNode* root) {
        return rec(root);
    }
};