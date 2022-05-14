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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int,int>inMap;
        for(int i=0;i<inorder.size();i++)
            inMap[inorder[i]]=i;
        
        TreeNode* root=buildTreePre(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1,inMap);
        return root;
    }
    
    TreeNode* buildTreePre(vector<int>&inorder,int is,int ie,vector<int>&preorder,int ps,int pe,unordered_map<int,int>&inMap)
    {
        if(ps>pe || is>ie) return NULL;
        TreeNode* root=new TreeNode(preorder[ps]);
        
        int inRoot=inMap[root->val];
        int numsLeft=inRoot-is;
        
        root->left=buildTreePre(inorder,is,inRoot-1,preorder,ps+1,ps+numsLeft,inMap);
        root->right=buildTreePre(inorder,inRoot+1,ie,preorder,ps+numsLeft+1,pe,inMap);
        
        return root;
    }
};