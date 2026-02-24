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
    int sumRootToLeaf(TreeNode* root,int x=0) {
        if(root==NULL) return 0;
        x<<=1;
        x+=root->val;
        if(root->right==NULL && root->left==NULL) return x;
        // int a=sumRootToLeaf(root->left,x);
        // int b=sumRootToLeaf(root->right,x);
        
        // cout<<root->val<<" "<<a<<" "<<b<<endl;;
        // return a+b;
        return sumRootToLeaf(root->left,x)+sumRootToLeaf(root->right,x);

        
    }
};