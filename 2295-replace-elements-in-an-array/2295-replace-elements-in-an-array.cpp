class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
           mp[nums[i]]=i;
        }
        
       for(auto i:operations){
           nums[mp[i[0]]]=i[1];
           mp[i[1]]=mp[i[0]];
       }
        return nums;
        
    }
};