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
   
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode * temp;
        q.push(root);
        q.push(NULL);
        int sum=0,mx=INT_MIN,level=1,x=1;
        while(q.size()>1)
        {
            temp=q.front();
            q.pop();

            if(temp==NULL)
            {
                if(sum>mx)
                {
                    mx=sum;
                    x=level;
                }
                sum=0;
                level++;
                q.push(NULL);
            }
            else
            {
                sum+=temp->val;
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                }
                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                }
            }
        }
          if(sum>mx)
                {
                    mx=sum;
                    x=level;
                }
        return x;
        
        
    }
};