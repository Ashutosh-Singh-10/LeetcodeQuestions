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
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode * par=head;
      
        ListNode * lst=head;
        head=head->next;
        int sum=0;
        while(head!=NULL) 
        {
            if(head->next==NULL) 
            {
                lst->val=sum;
                lst->next=NULL;
                return par;

            }
            if(head->val==0) 
            {
                lst->val=sum;
                lst->next=head;
                lst=head;
                sum=0;
            }
            sum+=head->val;
            head=head->next;
            
        }
        return par;
        
    }
};