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
    int countNodes(TreeNode* root) {
        TreeNode* _left=root, *_right=root;
        int l=0,r=0;
        while(_left){
            l++;
            _left=_left->left;
        }
        while(_right){
            r++;
            _right=_right->right;
        }
        if(r==l)return pow(2,l)-1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};