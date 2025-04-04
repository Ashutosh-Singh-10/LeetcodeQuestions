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
    int dfs(TreeNode * root)
    {
        if(root==NULL) return 0;
        return max(dfs(root->left),dfs(root->right))+1;
    }
    int dfs(TreeNode * root,int depth,int mxd,TreeNode *& ans)
    {
        if(root==NULL) return 0;
        if(depth==mxd) 
        {
            ans=root;
            return 1;
        }
        int y=dfs(root->right,depth+1,mxd,ans);
        int x=dfs(root->left,depth+1,mxd,ans);
        if(x+y==2) 
        {
            ans=root;
        }
        if(x+y>=1) return 1;
        return 0;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        
        int mxd=dfs(root);
        TreeNode * ans=NULL;
        cout<<mxd<<endl;
        // cout<<root->val<<endl;
        dfs(root,1,mxd,ans);
        return ans;
        
    }
};