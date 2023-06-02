class Solution {
public:
    vector<vector<int>>ans,ans1;
    void generate(vector<int>& nums,int i,vector<int>&v){
        if(i>nums.size()){
            return;
        }
        if(i<=nums.size()){
            ans.push_back(v);
        };
        if(i<nums.size()){
            v.push_back(nums[i]);
            generate(nums,i+1,v);
            v.pop_back();
            generate(nums,i+1,v);
        }
            
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>v;
        sort(nums.begin(),nums.end());
        generate(nums,0,v);
        set<vector<int>>s;
        for(int i=0;i<ans.size();i++){
            s.insert(ans[i]);
        }
        for(auto x:s){
            ans1.push_back(x);
        }
        return ans1;
    }
};