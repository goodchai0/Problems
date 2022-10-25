class Solution {
public:
    long long mod = 1e9 + 7;
    
    int dp[10004];
    int helper(int i,int n){
        if(i>n)
            return 1;
        // ans++;
        if(dp[i]!=-1)
            return dp[i];
        int include=helper(i+1,n);
        int exclude=helper(i+2,n);
        return dp[i]=(include%mod+exclude%mod)%mod;
    }
    int countHousePlacements(int n) {
        memset(dp,-1,sizeof(dp));
        int ans = helper(1, n);
        
        return (ans % mod * ans % mod) % mod;
    }
};