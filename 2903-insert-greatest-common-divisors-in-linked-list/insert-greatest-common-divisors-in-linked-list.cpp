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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        auto ans=head;
        auto temp=head;
        while(head->next!=NULL)
        {
            temp=head->next;
            head->next=new ListNode(__gcd(head->val,head->next->val));
            head=head->next;
            head->next=temp;
            head=head->next;
        }
        return ans;
        
    }
};