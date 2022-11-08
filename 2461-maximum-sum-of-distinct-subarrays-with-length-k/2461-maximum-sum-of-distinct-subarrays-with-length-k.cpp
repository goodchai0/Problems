class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        long long sum=0,ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            mp[nums[i]]++;
            
            if(i>=k-1){
                if(mp.size()==k)ans=max(ans,sum);
                sum-=nums[i-k+1];
                if(--mp[nums[i-k+1]]==0)mp.erase(nums[i-k+1]);
            }
           
        }
         return ans;
    }
};