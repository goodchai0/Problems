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
    TreeNode* prev=NULL;
    void flatten_(TreeNode* root){
        if(root==NULL)
            return ;
        flatten_(root->right);
        flatten_(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root;
    }
    void flatten(TreeNode* root) {
        flatten_(root);
    }
//     example 1, 4 will be connected to to 5 , because prev=node 5. this is a recursion .
};

