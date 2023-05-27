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
    ListNode* reverseList(ListNode* head) {
        ListNode* rev=head;
        ListNode* prev=NULL;
        while(rev!=NULL){
            ListNode* temp=rev;
            rev=rev->next;
            temp->next=prev;
            prev=temp;
        }
        return prev;
    }
};