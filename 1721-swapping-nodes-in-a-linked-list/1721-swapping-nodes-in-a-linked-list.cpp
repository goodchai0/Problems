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
    ListNode* swapNodes(ListNode* head, int k) {

        ListNode* one=head;
        ListNode* two=head;
        ListNode* last=head;
        int k1=k;
        while(--k1){
            if(k!=1)
                one=one->next;
            else break;
        }
        while(two!=NULL){
            if(k==0){
                last=last->next;
                two=two->next;
            }else{
                k--;
                two=two->next;
            }
            
        }
        swap(one->val,last->val);
        
        return head;
    }
};