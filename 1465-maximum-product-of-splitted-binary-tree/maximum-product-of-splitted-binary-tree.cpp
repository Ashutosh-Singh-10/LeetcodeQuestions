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
    int get_sum(TreeNode * root)
    {
        if(root==NULL) return 0;
        return root->val+get_sum(root->left)+get_sum(root->right);
    }
    int algo (TreeNode *root,int &ans,int sum)
    {

        if(root==NULL) return 0;


        int left=algo(root->left,ans,sum);
        int right=algo(root->right,ans,sum);
        // cout<<(sum-left-root->val)*(root->val+left)<<"  "<<
        // (sum-right-root->val)*(root->val+right)<<endl;
     
        if(abs(sum-2*(right+left+root->val))<abs(sum-2*ans))
        {
            ans=right+root->val+left;
        }
        return root->val+left+right;

    }
    int maxProduct(TreeNode* root) {
      
        int ans=0;
        int sum=get_sum(root);

        algo(root,ans,sum);
        cout<<"the ans is"<<ans<<"  sum  "<<sum;
        // ans%=10000000007;
        // sum%=10000000007;
        
        long long int x=((long long int)ans)*(long long int)(sum-ans);
        x=x%(1000000007);
        return x;        
    }
};