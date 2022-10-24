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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m,vector<int>(n,-1));
        
        int t=0,b=m-1,l=0,r=n-1;
        int j=0;
        while(head!=NULL){
            
            for(int i=l;i<=r;i++){
                if(head==NULL)return ans;
                ans[t][i]=head->val;
                head=head->next;
            }
            t++;
            
            for(int i=t;i<=b;i++){
                if(head==NULL)return ans;
                ans[i][r]=head->val;
                head=head->next;
            }
            r--;
            
            for(int i=r;i>=l;i--){
                if(head==NULL)return ans;
                ans[b][i]=head->val;
                head=head->next;
            }
            b--;
            for(int i=b;i>=t;i--){
                if(head==NULL)return ans;
                ans[i][l]=head->val;
                head=head->next;
            }
            l++;
            
        }
        return ans;
        
    }
};