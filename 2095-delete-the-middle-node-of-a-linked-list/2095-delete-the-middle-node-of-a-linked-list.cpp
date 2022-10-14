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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow= new ListNode;
        ListNode* fast=new ListNode;
        ListNode* prev;
        if (head == NULL) {
          return NULL;
       }
        fast=head;
        slow=head;
        prev=head;
        if(fast->next==NULL)
        {
            delete head;
            return NULL;
        }
        
        while(fast!=NULL && fast->next!=NULL){
            if(head!=slow) prev=prev->next;
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* temp=slow->next;
        cout<<slow->val;
        cout<<prev->val;
        prev->next=prev->next->next;
        // prev->next=slow->next;
         delete(slow);
        return head;
    }
};