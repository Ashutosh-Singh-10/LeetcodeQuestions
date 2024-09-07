/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
 int check(TreeNode * root,ListNode * head)
 {
    if(head==NULL) return 1;
    if(root==NULL) return 0;
    if(root->val!=head->val) return 0;
    if(check(root->left,head->next) || check(root->right,head->next)) return 1;
    return 0 ;

 }
 int dfs(TreeNode * root,ListNode * head)
 {
    if(root==NULL) return 0;
    if(check(root,head)) return 1;
    if(dfs(root->left,head) || dfs(root->right,head)) return 1;
    return 0;
 }
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        
        return dfs(root,head);
    }
};