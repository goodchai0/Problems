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
    
    TreeNode* head=new TreeNode(0);
    TreeNode *ptr=head;
    
    void tree(TreeNode* root)
    {
        if(root==NULL)
            return;
        tree(root->left);
        head->right=new TreeNode(root->val);
        head=head->right;
        tree(root->right);
        return;
    }
    TreeNode* increasingBST(TreeNode* root) {
        tree(root);
        return ptr->right;
    }
};