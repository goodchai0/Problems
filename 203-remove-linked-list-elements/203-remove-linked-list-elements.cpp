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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)
            return NULL;
        if(head->val==val)
            return removeElements(head->next,val);
        else
        {
            head->next=removeElements(head->next,val);
            return head;
        }
        
    }
};


// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) {
        
//         if(head==NULL)
//             return NULL;
//         ListNode* h=head;
        
        
//         while( h->next!=NULL )
//         {
    
//             if( h!=NULL && h->next->val==val)
//             {
//                 h->next=h->next->next;
//                 cout<<h->val<<" ";
//             }
//             else h = h->next;
                 
//         }
//         if(head->val==val)
//             head=head->next;
//         return head;
//     }
// };