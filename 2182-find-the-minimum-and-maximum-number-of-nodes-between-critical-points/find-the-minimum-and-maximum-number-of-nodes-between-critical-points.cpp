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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int ansMn=INT_MAX,ansMx=-1,count=0,longDist=-1;
        int prev=head->val;
        head=head->next;
        while(head->next!=NULL)
        {
            if(
                (head->val>prev && head->val>head->next->val) || 
                (head->val<prev && head->val<head->next->val)
                )
            {
                if(longDist>-1)
                {
                    ansMn=min(count,ansMn);
                    ansMx=max(longDist,ansMx);
                    count=0;
                }
                else 
                {
                    longDist=0;
                    count=0;
                }
            }
            
      
            count++;
            if(longDist>-1)
            longDist++;
            prev=head->val;
            head=head->next;

        }
        if(ansMn==INT_MAX) return {-1,-1};
        return {ansMn,ansMx};
        
    }
};