class Solution {
public:
    void inorder(TreeNode* root,vector<int> &ans) {
        //base case
        if(root == NULL) {
            return ;
        }

        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);

    }
    int minDiffInBST(TreeNode* root) {
        if(!root) return 0;
        vector<int> a;
        inorder(root,a);
        int mini = INT_MAX;
        for(int i=0;i<a.size()-1;i++) mini=min(mini,a[i+1]-a[i]);
        return mini;
    }
};