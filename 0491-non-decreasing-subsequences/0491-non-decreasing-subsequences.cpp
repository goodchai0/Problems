class Solution {
public:
    void helper(int idx,vector<int>nums,set<vector<int>>&ans,vector<int>&curr){
        if(idx>=nums.size()){
            if(curr.size()>=2){
                ans.insert(curr);
            }
            return;
        }
        
        if(curr.size()==0 || nums[idx]>=curr.back() ){
            curr.push_back(nums[idx]);
            helper(idx+1,nums,ans,curr);
            curr.pop_back();
            helper(idx+1,nums,ans,curr);
        }
        else{
            helper(idx+1,nums,ans,curr);
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>>ans;
        vector<int>curr;
        helper(0,nums,ans,curr);
        return vector(ans.begin(),ans.end());
    }
};