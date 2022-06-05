class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<int,int>mp;
        int count=0,currSum=0;
        if(nums.size()==0)
            return 0;
        for(auto x:nums)
        {
            currSum+=x;
            if(currSum==k)
                count++;
            if(mp.find(currSum-k)!=mp.end())
                count+=mp[currSum-k];
            mp[currSum]++;
        }
        return count;
    }
};