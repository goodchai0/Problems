class Solution {
public:
    vector<vector<int>> ans;
    void generate(int k,int n,vector<int>v,int sum,int j){
        
        if(sum==n && v.size()==k){
            ans.push_back(v);
        }
        if(v.size()>k)return;
        for(int i=j;i<=9;i++){
            v.push_back(i);
            generate(k,n,v,sum+i,i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>v;
        generate(k,n,v,0,1);
        return ans;
    }
};