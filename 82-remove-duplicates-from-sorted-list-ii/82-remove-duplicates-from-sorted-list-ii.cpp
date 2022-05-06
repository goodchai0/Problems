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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* node_next=head;
        ListNode* prev=new ListNode(0,head);
        ListNode* dummy=prev;
        
        while(node_next)
        {
            if(node_next->next!=NULL && node_next->val==node_next->next->val)
            {
                while(node_next->next!=NULL && node_next->val==node_next->next->val)
                {
                    node_next=node_next->next;
                }   
                prev->next=node_next->next;
            }
            else 
            {
                prev=prev->next;    
                
            }
           node_next=node_next->next;
        }
        
        return dummy->next;
    }
};