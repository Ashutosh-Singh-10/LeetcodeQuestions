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
    void traversal(TreeNode * root,int pa,int grandpa,int &ans)
    {
        if(root==NULL) return ;
        if(grandpa%2==0)
        {
            ans+=root->val;
        }
        grandpa=pa;
        pa=root->val;
        traversal(root->left,pa,grandpa,ans);
        traversal(root->right,pa,grandpa,ans);
        return ;
    }
    int sumEvenGrandparent(TreeNode* root) {
        int ans=0;
        traversal(root,1,1,ans);
        return ans;

        
    }
};