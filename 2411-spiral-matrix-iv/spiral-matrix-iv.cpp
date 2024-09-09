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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m,vector<int>(n,-1));
          int start=0;
        int end=matrix[0].size()-1;
        int top=0;
        int bottom=matrix.size()-1;
        int size=(matrix.size())*(matrix[0].size());
        vector<int> ans;
        if(head==NULL) return matrix;
        
        while((bottom-top>=0 || end-start>=0 )&& size)
        {
            for(int i=start;i<=end;i++)
            {
                size--;
                matrix[top][i]=head->val;
                head=head->next;
                if(head==NULL) return matrix;
            }
            top++;
            for(int i=top;i<=bottom;i++)
            {
                size--;
                matrix[i][end]=head->val;
                head=head->next;
                if(head==NULL) return matrix;

            }
            end--;
            if(!size) break;

            for(int i=end;i>=start;i--)
            {
                size--;
                matrix[bottom][i]=head->val;
                head=head->next;
                if(head==NULL) return matrix;
            }
            bottom--;
            for(int i=bottom;i>=top;i--)
            {
                size--;
                matrix[i][start]=head->val;
                head=head->next;
                if(head==NULL) return matrix;

            }
            start++;
        }
        return matrix;
        
    }
};