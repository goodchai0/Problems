/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<int,int>mp;
        queue<TreeNode*>q;
        
        q.push(root);
        mp[0]=root->val;
        
        int level=0;
        while(q.empty()!=1){
            auto n=q.size();
            level++;
            for(int i=0;i<n;i++){
                auto r=q.front();
                q.pop();
                if(r->left){
                    mp[level]+=r->left->val;
                    q.push(r->left);
                }
                if(r->right){
                    mp[level]+=r->right->val;
                    q.push(r->right);
                }
            }
        }
        
        q.push(root);
        root->val=0;
        level=0;
        while(!q.empty()){
            auto n=q.size();
            level++;
            for(int i=0;i<n;i++){
                auto it=q.front();
                q.pop();
                int l=it->left!=NULL?it->left->val:0;
                int r=it->right!=NULL?it->right->val:0;
                if(it->left){
                    q.push(it->left);
                    it->left->val=mp[level]-l-r;
                }
                if(it->right){
                    q.push(it->right);
                    it->right->val=mp[level]-l-r;
                }
            }
            
        }
        return root;
    }
};