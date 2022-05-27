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
    
    int helper(TreeNode* root,long long sum)
    {
        if(root==NULL)
            return 0;
        int res=0;
        if(root->val==sum)res++;
        res+=helper(root->left,sum-root->val);
        res+=helper(root->right,sum-root->val);
        return res;
    }
    int pathSum(TreeNode* root, long long sum) {
      if(!root)
          return 0;
        return pathSum(root->left,sum)+helper(root,sum)+pathSum(root->right,sum);
    }
};