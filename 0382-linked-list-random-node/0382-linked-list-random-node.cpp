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
    ListNode* head=NULL;
    Solution(ListNode* h) {
        head=h;
    }
    
    int getRandom() {
        //int random=rand();
        
        ListNode* start=head;
        ListNode* ans;
        int n=1;
        while(start){
            if(rand()%n==0)
                ans=start;
           
                start=start->next;
                n++;
            
        }
        
        
        return ans->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */