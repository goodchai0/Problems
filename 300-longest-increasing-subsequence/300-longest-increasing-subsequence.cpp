class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size()+1,1);
        int n=nums.size();
        int ma=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(nums[j]<nums[i] && dp[j]+1>dp[i] )
                    dp[i]=1+dp[j];
                ma=max(ma,dp[i]);
            }
           
        }
        return ma;
    }
};