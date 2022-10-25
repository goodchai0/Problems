class Solution {
public:
    long long mod = 1e9 + 7;
    
    int dp[10004];
    int helper(int n){
        
        dp[0]=1,dp[1]=2;
        for(int i=2;i<=n;i++){
            dp[i]+=dp[i-1]%mod;
            dp[i]+=dp[i-2]%mod;
        }
        return dp[n]%mod;
    }
    int countHousePlacements(int n) {
        memset(dp,0,sizeof(dp));
        int ans = helper(n);
        
        return (ans % mod * ans % mod) % mod;
    }
};