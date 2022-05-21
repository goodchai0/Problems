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
    TreeNode* pruneTree(TreeNode* root) {
        if(contain(root)==0)
            return NULL;
        return root;
    }
    
    bool contain(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
        {
            if(root->val==0)
            return 0;
            else return 1;
            
        }
        bool left=contain(root->left);
        bool right=contain(root->right);
        if(left==0)
            root->left=NULL;
        if(right==0)
            root->right=NULL;
        
        return left+right+(root->val==1?1:0);
    }
};