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
 int Traversal(TreeNode * root,int val)
 {
    if(root==NULL) return val;
    auto x=Traversal(root->right,val);
    x+=root->val;
    root->val=x;
    return Traversal(root->left,x);
 }
class Solution {
public:

    TreeNode* bstToGst(TreeNode* root) {
        Traversal(root,0);
        return root;
        
    }
};