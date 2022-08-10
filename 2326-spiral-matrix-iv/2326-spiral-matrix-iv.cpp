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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* h) {
        vector<vector<int>>v(m,vector<int>(n,-1));
        int left=0,right=n-1,top=0,bottom=m-1;
        ListNode* head=h;
        while(head!=NULL && left<=right && top<=bottom){
            for(int i=left;i<=right;i++)
            {   
                if(head!=NULL)
                {
                    v[top][i]=head->val;
                    head=head->next;
                }  
                else{
                    break;
                }
            }
            top++;
            for(int i=top;i<=bottom;i++)
            {
                if(head!=NULL)
                {
                    v[i][right]=head->val;
                    head=head->next;
                }
                else{
                    break;
                }
                
            }
            right--;
            for(int i=right;i>=left;i--)
            {
                if(head!=NULL)
                {
                    v[bottom][i]=head->val;
                    head=head->next;
                }
                else{
                    break;
                }
                
            }
            bottom--;
            for(int i=bottom;i>=top;i--)
            {
                if(head!=NULL)
                {    
                    v[i][left]=head->val;
                    head=head->next;
                }
                else{
                    break;
                }
            }
            left++;
        }
        return v;
    }
};