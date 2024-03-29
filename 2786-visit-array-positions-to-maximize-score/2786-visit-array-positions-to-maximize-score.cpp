class Solution {
public:
    long long helper(vector<int>&nums, int i,int n,int p,int x,vector<vector<long long>>&dp){
        if(i==n)return 0;
        
        if(dp[i][p]!=-1)return dp[i][p];
        long long take=nums[i]+helper(nums,i+1,n,nums[i]%2,x,dp);
        if(nums[i]%2!=p){
            take-=x;
            // cout<<nums[i]<<" "<<take<<endl;
        }
        long long notTake=helper(nums,i+1,n,p,x,dp);
        dp[i][p]=max(notTake,take);
        return dp[i][p];
    }
    
    
    long long maxScore(vector<int>& nums, int x) {
        int n=nums.size();
        vector<vector<long long>>dp(n+1,vector<long long>(2,0));        
        for(int i=n-1;i>=0;i--){
            for(int p = 0; p <= 1; p++) {
                long long take=nums[i]+dp[i+1][nums[i]%2];
                if(i>0 && nums[i]%2!=p){
                    take-=x;
                }
                long long notTake=dp[i+1][p];
                dp[i][p]=max(notTake,take);
            }
        }
        return min(dp[0][1],dp[0][0]);
    }
};