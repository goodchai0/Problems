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
    void helper(TreeNode* root,unordered_map<int,int>&mp){
        if(!root) return ;
        mp[root->val]++;
        cout<<root->val<<" ";
        helper(root->left,mp);
        helper(root->right,mp);
    }
    bool findTarget(TreeNode* root, int k) {
        
        unordered_map<int,int>mp;
        helper(root,mp);
        if(mp.size()<2)
            return false;
        for(auto [x,y]:mp){
            // cout<<x<<" "<<y<<endl;
            // cout<<k-x<<endl;
            if(mp.find(k-x)!=mp.end()){
                if(k-x==x){
                     if(mp[k-x]>1)
                        return true;
                     else continue;
                }
                return true;
            }
        }
        return false;
    }
};