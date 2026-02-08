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
    int algo(TreeNode * root,int & bal)
    {
        if(root==NULL) return 0;
        int lft=algo(root->left,bal);
        int r=algo(root->right,bal);
        if(abs(lft-r)>1) 
        {
            bal=0;
        }
        return max(r,lft)+1;
        
    }
    bool isBalanced(TreeNode* root) {
        int bl=1;
        algo(root,bl);
        return bl;
        
    }
};