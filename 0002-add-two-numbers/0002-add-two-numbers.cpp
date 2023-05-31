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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* L1=l1;
        ListNode * L2=l2;
        ListNode* start=new ListNode(-1);
        ListNode* startHead=start;
        int carry=0;
        while(l1 && l2){
            int x=l1->val+l2->val+carry;
            int n=x%10;
            start->next=new ListNode(n);
            carry=x/10;
            start=start->next;
            l1=l1->next;
            l2=l2->next;
        }
        if(l1){
            while(l1){
                int x=l1->val+carry;
                int n=x%10;
                start->next=new ListNode(n);
                carry=x/10;
                start=start->next;
                l1=l1->next;
            }
        }
        if(l2){
            while(l2){
                int x=l2->val+carry;
                int n=x%10;
                start->next=new ListNode(n);
                carry=x/10;
                start=start->next;
                l2=l2->next;
            }
        }
        if(carry){
            start->next=new ListNode(carry);
        }
        return startHead->next;
    }
};