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

 int fun(TreeNode * root,string &ans,int end)
 {
    if(root==NULL) return 0;
    if(root->val==end) return 1;
    if(fun(root->left,ans,end))
    {
        ans.push_back('L');
        return 1;
    }
    else if(fun(root->right,ans,end))
    {
        ans.push_back('R');
        return 1;
    }
    return 0;


 }
 int search(TreeNode * root,string &ans,int start,int end)
 {
    if(root==NULL) return 0;
    int l=search(root->left,ans,start,end);
    int r=search(root->right,ans,start,end);
    int cur=0;
    if(root->val==start) cur=1;
    else if(root->val==end) cur=-1;

    if((cur==0) + (l==0) +(r==0)<2)
    {
        int e=max({l,cur,r});
        fun(root,ans,end);
        while(e>1)
        {
            ans.push_back('U');
            e--;

        }
        reverse(ans.begin(),ans.end());
        
        


        return 0;
    }
    int mx=max({r,l,cur});
    if(mx>0) return mx+1;
    return min({r,l,cur});
 }
class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string ans;
        search(root,ans,startValue,destValue);
        return ans;

        
    }
};