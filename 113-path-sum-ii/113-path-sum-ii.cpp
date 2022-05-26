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
    vector<vector<int>>ans;
    void helper(TreeNode* root,vector<int>res,int sum,int target)
    {
        if(!root)
            return ;
        sum+=root->val;
        res.push_back(root->val);
        if(sum==target && !root->left && !root->right)
        {
            ans.push_back(res);
            return;
        }
        helper(root->left,res,sum,target);
        helper(root->right,res,sum,target);
        
        
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>res;
        if(!root)
            return ans;
        helper(root,res,0,targetSum);
        return ans;
    }
};