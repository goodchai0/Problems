class Solution {
public:
    vector<vector<int>>ans;
    void generate(vector<int>& candidates, int target,vector<int>& v, int i){
        if(target<0 || i>=candidates.size()){
            return;
        }
        if(target==0 && i==candidates.size()-1){
            ans.push_back(v);
        }
        v.push_back(candidates[i]);
        generate(candidates,target-candidates[i],v,i);
        v.pop_back();
        generate(candidates,target,v,i+1);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>v;
        generate(candidates,target,v,0);
        return ans;
    }
};