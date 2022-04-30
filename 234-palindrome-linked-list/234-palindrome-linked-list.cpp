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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return true;
        
        ListNode* slow=head;
        ListNode* faster=head;
        
        while(faster->next!=NULL && faster->next->next!=NULL)
        {
            slow=slow->next;
            faster=faster->next->next;
        }
        slow->next=reverse(slow->next);
        slow=slow->next;
        
        while(slow!=NULL)
        {
            if(head->val!=slow->val)
                return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
    
    ListNode* reverse(ListNode* head)
    {
        ListNode *prev=NULL;
        ListNode *next_node=NULL;
        
        while(head!=NULL)
        {
            next_node=head->next;
            head->next=prev;
            prev=head;
            head=next_node;
        }
        return prev;
    }
};