class Solution {
public:
    int mod=1e9+7;
    int helper(int s,int end,int k,vector<vector<int>>&dp){
        if(k==0 && s==end){
            return 1;
        }
        if(k<=0)return 0;
        if(dp[s+1000][k]!=-1)
        {
            return dp[s+1000][k];
        }
        
        int l=helper(s+1,end,k-1,dp);
        int r=helper(s-1,end,k-1,dp);
        
        return dp[s+1000][k]=(r+l)%mod;
    }
    
    int numberOfWays(int startPos, int endPos, int k) {
        int count=0;
        vector<vector<int>>dp(3000,vector<int>(k+1,-1));
       
        return helper(startPos,endPos,k,dp)%mod;
    }
};