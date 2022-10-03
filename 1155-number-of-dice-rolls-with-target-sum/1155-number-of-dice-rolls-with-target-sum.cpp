class Solution {
public:
    #define MOD 1000000007
    int solve(int d,int f,int target,vector<vector<int>>&dp){
        if(d==0 && target==0) return 1;
        if(d<=0 || target<=0) return 0;
        
        if(dp[d][target]!=-1) return dp[d][target];
        
        int sum=0;
        
        for(int i=1;i<=f;i++){
            sum=(sum%MOD + solve(d-1,f,target-i,dp)%MOD)%MOD;
        }
        return dp[d][target]=sum;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(n,k,target,dp);
    }
};