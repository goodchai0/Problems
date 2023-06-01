class Solution {
public:
    vector<vector<int>>ans,ans1;
    void generate(vector<int>& candidates, int target,vector<int>& v, int i){
        
        if(target<0 || i>candidates.size()){
            return;
        }
        if(target==0 && i==candidates.size()){
            ans.push_back(v);
        }
        if(i>candidates.size()-1)return;
        v.push_back(candidates[i]);
        generate(candidates,target-candidates[i],v,i+1);
        v.pop_back();
        
        while(i+1 <candidates.size() && candidates[i] == candidates[i+1]) i++;
        generate(candidates,target,v,i+1);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>v,candidate;
        set<vector<int>>s;
       
        sort(candidates.begin(),candidates.end());

        generate(candidates,target,v,0);
        
        for(int i=0;i<ans.size();i++){
            s.insert(ans[i]);
        }
        for(auto x:s){
            ans1.push_back(x);
        }
        sort(ans1.begin(),ans1.end());
        return ans1;
    }
};