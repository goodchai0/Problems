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
    
    TreeNode* trim(TreeNode* root,int low,int high)
    {
        if(root==NULL)
            return NULL;
        
        TreeNode *leftnode=trim(root->left,low,high);
            if(leftnode!=root->left)
            {
                root->left=leftnode;
            }
        TreeNode *rightnode=trim(root->right,low,high);
            if(rightnode!=root->right)
            {
                root->right=rightnode;
            }
        if(root->val>high || root->val<low)
            return (root->left)?root->left:root->right;
        
        return root;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return trim(root,low,high);
    }
};