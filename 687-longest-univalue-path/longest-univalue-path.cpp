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
int ans=1;
int dfs(TreeNode * root)
{
    if(root==NULL) return -1;
    int x,a,y,b;
    if(root->left==NULL) 
    {
        a=-10000;x=-10000;
    }
    else
    {
        a=dfs(root->left);
        x=root->left->val;
    }
    if(root->right==NULL) 
    {
        b=-10000;y=-10000;
    }
    else
    {
        b=dfs(root->right);
        y=root->right->val;
    }

    int val=root->val;
    if(x==val && y==val)
    {
        ans=max(ans,a+b+1);
        return max(a,b)+1;
    }
    else if(x==val) 
    {
        ans=max(ans,a+1);
        return a+1;
    }
    else if(y==val)
    {
        ans=max(ans,b+1);
        return b+1;
    }
    return 1;
    
}
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        ans=1;
        if(root==NULL) return 0;
        dfs(root);
        return ans-1;
        
    }
};