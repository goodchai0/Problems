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
    void helper(TreeNode* root,string&s){
        if(root==NULL)
            return;
        string x=to_string(root->val);
        // cout<<x<<root->val<<endl;
        s+=x;
        if(root->left)
        {
            s+='(';
            helper(root->left,s);
            s+=')';
        }
        if(root->right)
        {
            if(!root->left)s+="()";
            s+='(';
            helper(root->right,s);
            s+=')';
        }
        
        return;
        
    }
    string tree2str(TreeNode* root) {
        string s="";
        helper(root,s);
        return s;
    }
};