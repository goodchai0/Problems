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
    
    void lca(TreeNode *root, int target,string& path,string &s){
        if(root->val==target){
            s=path;
            return;
        }
        if(root->left!=NULL){
            path.push_back('L');
            lca(root->left,target,path,s);
            path.pop_back();
        }
        if(root->right!=NULL){
            path.push_back('R');
            lca(root->right,target,path,s);
            path.pop_back();
        }
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string s1="",s2="";
        string temp="";
        lca(root,startValue,temp,s1);
        temp="";
        lca(root,destValue,temp,s2);
        string ans="";
        cout<<s1<<" "<<s2<<endl;
        int length=min(s1.size(),s2.size());
        int i=0;
        for(i;i<length;i++)
            if(s1[i]!=s2[i]) break;
        
        for(int j=i;j<s1.size();j++)
            ans+='U';
        
        for(int j=i;j<s2.size();j++)
            ans+=s2[j];
        
        return ans;
        
    }
};