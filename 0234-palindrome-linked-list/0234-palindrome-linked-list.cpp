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
        ListNode* slow=head;
        ListNode* fast=head;
        stack<int>s;
                    // cout<<s.top()<<" ";
        s.push(slow->val);

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            s.push(slow->val);
        }
        if(fast==NULL){
            s.pop();
            while(!s.empty()){
                
                if(s.top()!=slow->val)return false;
                else{
                    
                    s.pop();slow=slow->next;
                }
            }
        }
        else{
            while(!s.empty()){
                if(s.top()!=slow->val)return false;
                else{
                    s.pop();slow=slow->next;
                }
            }
        }
        return true;
    }
};