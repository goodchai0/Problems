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
    ListNode* ans1;
    ListNode* helper(ListNode* head,ListNode* prev){
        if(head==NULL)
        {
            ans1=prev;
            return prev;
        }
        ListNode* temp=head;
        head=head->next;
        temp->next=prev;
        helper(head,temp);
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* ans=helper(head,NULL);
        return ans1;
    }
};