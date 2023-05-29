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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr1=head;
        ListNode* ptr2=head;
        ListNode* prev=new ListNode();

        int x=n;
        // if(x==1 && head->next==NULL){
        //     ptr2=ptr2->next;
        //     return ptr2;
        // }
        while(ptr2!=NULL){
            if(x==0){
                prev=ptr1;
                ptr1=ptr1->next;
                ptr2=ptr2->next;
                
            }
            else{
                ptr2=ptr2->next;
                x--;
            }
            
        }
        if(ptr1==head)
            return head->next;
        prev->next=ptr1->next;
        return head;
    }
};