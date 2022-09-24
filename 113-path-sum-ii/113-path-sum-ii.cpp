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
    
    void helper(TreeNode* root, int target,vector<int>&temp,vector<vector<int>>&ans,int &sum){
        if(root==NULL)
            return;
        sum+=root->val;
        temp.push_back(root->val);
        
        if(sum==target && !root->left && !root->right){
            ans.push_back(temp);
            return;
        }
        
        if(root->left!=NULL)
        {
            // temp.push_back(root->val);
            // sum+=root->val;
            helper(root->left,target,temp,ans,sum);
            temp.pop_back();
            sum-=root->left->val;
        }
        if(root->right!=NULL )
        {
            // temp.push_back(root->val);
            // sum+=root->val;
            helper(root->right,target,temp,ans,sum);
            temp.pop_back();
            sum-=root->right->val;
        }
        // helper(root->left,target,temp,ans,sum);
        // helper(root->right,target,temp,ans,sum);
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        int sum=0;
        helper(root,targetSum,temp,ans,sum);
        return ans;
    }
};