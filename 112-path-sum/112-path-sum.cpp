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
    bool ans=false;
    void helper(TreeNode*root,int sum,int target)
    {
        if(!root)
            return ;
        sum+=root->val;
        if(root->left==NULL && root->right==NULL && sum==target)
        {
            ans =true;
            return;
        }
        helper(root->left,sum,target);
        helper(root->right,sum,target);
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return ans;
        helper(root,0,targetSum);
        if( ans==true)
            return true;
        else return false;
    }
};