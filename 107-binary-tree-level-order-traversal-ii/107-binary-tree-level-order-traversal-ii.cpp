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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        TreeNode* curr;
        q.push(root);
        if(root==NULL)
            return ans;
        
        while(!q.empty()){
            int size=q.size();
            vector<int>res;
            for(int i=0;i<size;i++){
        
                curr=q.front();
                q.pop();
                
                if(curr->left) q.push(curr->left);
                if(curr->right)q.push(curr->right);
                
                res.push_back(curr->val);
            }
            
            ans.push_back(res);
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};