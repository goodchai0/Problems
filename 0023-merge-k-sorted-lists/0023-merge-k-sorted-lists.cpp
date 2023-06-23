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
class mycmp{
    public:
         bool operator()(ListNode* a,ListNode* b){
             return a->val>b->val;
         }
    };
class Solution {
public:
    
    
    ListNode* mergeKLists(vector<ListNode*>& list) {
        priority_queue<ListNode*,vector<ListNode*>,mycmp>pq;
        for(ListNode* x:list){
            if(x)pq.push(x);
        }
        ListNode* head=NULL;
        ListNode* rear=NULL;
        
        while(!pq.empty()){
            ListNode* x=pq.top();
            pq.pop();
            if(head==NULL){
                head=x;
                rear=x;
            }
            else{
                rear->next=x;
                rear=x;
            }
            if(x->next)pq.push(x->next);
        }
        
        return head;
    }
};