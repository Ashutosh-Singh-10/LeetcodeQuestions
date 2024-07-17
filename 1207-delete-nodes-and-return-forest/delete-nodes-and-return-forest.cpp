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
 bool fun(TreeNode * root,vector<TreeNode * > &ans,int flag,set<int> &st)
 {
    if(root==NULL) return 0;
    if(st.count(root->val)) 
    {
        if(fun(root->left,ans,1,st))
        {
            root->left=NULL;
        }
        if(fun(root->right,ans,1,st))
        {
            root->right=NULL;
        }
        return 1;
    }
    if(flag==1)
    {
        ans.push_back(root);
    }
    if( fun(root->left,ans,0,st))
    {
        root->left=NULL;
    }
    if(fun(root->right,ans,0,st))
    {
        root->right=NULL;
    }
    return 0;

 }
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode * > ans;
        set<int> st;
        for(auto &i:to_delete) st.insert(i);
        fun(root,ans,1,st);
        return ans;
        
    }
};