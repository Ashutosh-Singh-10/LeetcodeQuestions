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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode * tmp=new ListNode(-1);
        tmp->next=head;
        ListNode * prev=tmp;
        set<int> st;
        for(auto &i:nums) st.insert(i);
        while(head!=NULL)
        {
            if(st.count(head->val)) 
            {
                head=head->next;
                continue;
            }
            prev->next=head;
            prev=head;
            head=head->next;

        }
        prev->next=NULL;
        return tmp->next;



        
    }
};