/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/




class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        unordered_map<Node* ,Node*> mp;
        Node * tmp=head;
        Node * start=new Node(head->val);
        mp[head]=start;
        Node *tmp2=start;
        while(head->next!=NULL)
        {
            head=head->next;
            start->next=new Node(head->val);
            start=start->next;
            mp[head]=start;
        }
        head=tmp;
        while(head!=NULL)
        {
            mp[head]->random=mp[head->random];
            head=head->next;
        }
        return tmp2;
        


   
    }
};