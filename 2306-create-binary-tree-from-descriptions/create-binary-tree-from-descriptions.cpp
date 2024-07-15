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
 TreeNode * fun(vector<pair<int,int>>&vec,vector<int> &val,int cur)
 {
    if(cur==-1) return NULL;
    auto x=fun(vec,val,vec[cur].first);
    auto y=fun(vec,val,vec[cur].second);
    TreeNode * root=new TreeNode(val[cur]);
    root->left=x;
    root->right=y;
    return root;

 }
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& tree) {
        int n=tree.size()+1;
        vector<pair<int,int>> vec(n,{-1,-1});
        vector<int> val(n);
        vector<int> cnt(n,0);
        map<int,int> mp;
        int j=0;
        for(auto &i:tree)
        {
            if(mp.count(i[0])==0)
            {
                mp[i[0]]=j;
                j++;
            }
            if(mp.count(i[1])==0)
            {
                mp[i[1]]=j;
                j++;
            }

        }
        for(auto &i:tree)
        {
            if(i[2]==0)
            {
                vec[mp[i[0]]].second=mp[i[1]];
            }
            else 
                vec[mp[i[0]]].first=mp[i[1]];

            val[mp[i[1]]]=i[1];
            val[mp[i[0]]]=i[0];
            cnt[mp[i[1]]]++;

        }
        int root=0;
        for(int i=0;i<n;i++)
        {
            if(cnt[i]==0)
            {
                root=i;
                break;
            }
        }
        return fun(vec,val,root);


        
    }
};