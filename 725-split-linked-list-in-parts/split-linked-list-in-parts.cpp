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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode *> in(k),curr(k);
        ListNode * temp;
        temp=head;
        int cnt=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            cnt++;
        }
        int total=cnt;
        auto a=in[0];
        int n=k;
        for(int i=0;i<k;i++)
        {
            in[i]=new ListNode(99);
            a=in[i];
            // curr[i]=in[i];
            for(int j=0;j<(cnt/n)+(cnt%n!=0?1:0);j++)
            {
                a->next=head;
                head=head->next;
                a=a->next;
            }
            cnt-=cnt/n+(cnt%n?1:0);
            n--;
            // cout<<cnt<<"  ";
            // cnt-=cnt%k?1:0;
            a->next=NULL;

        }
        for(auto &i:in)
        {
            i=i->next;

        }
        return in;
        
        

        

        
    }
};