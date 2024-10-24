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
    bool check(TreeNode * root1,TreeNode * root2)
    {
        if(root1==NULL && root2==NULL) return 1;
        if((root1==NULL && root2!=NULL) || (root1!=NULL && root2==NULL)) return 0;
        if(root1->val!=root2->val) return 0;
        return (check(root1->left,root2->right) && check(root1->right,root2->left)) || (check(root1->left,root2->left) && check(root1->right,root2->right));
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return check(root1,root2);

        
    }
};