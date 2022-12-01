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
    ListNode* removeNodes(ListNode* head) {
        if(head->next==NULL) return head;
        
        stack<ListNode*>s;
        
        ListNode* x=head;
        while(x!=NULL){
            while(!s.empty() && s.top()->val<x->val)
                    s.pop();
             s.push(x);
             x=x->next;
        }
        if(s.empty())return NULL;
        stack<ListNode*>s1;
        while(!s.empty()){
            s1.push(s.top());
            s.pop();
        }
        ListNode* start=new ListNode(0);
        head=start;
        while(!s1.empty()){
            start->next=s1.top();
            s1.pop();
            start=start->next;
        }
        
        return head->next;
        
    }
};