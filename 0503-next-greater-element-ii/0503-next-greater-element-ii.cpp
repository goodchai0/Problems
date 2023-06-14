class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>s;
        map<int,int>mp;
        for(int i=2*nums.size()-1;i>=0;i--){
            while(!s.empty() && nums[s.top()]<=nums[i%nums.size()])s.pop();
            mp[i%nums.size()]=(s.empty())?-1:nums[s.top()];
            s.push(i%nums.size());
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};