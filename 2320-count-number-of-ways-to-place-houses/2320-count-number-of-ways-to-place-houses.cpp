class Solution {
public:
    #define ll long long
    #define mod 1000000007
    int countHousePlacements(int n) {
        vector<ll>dp(n+1,0);
        dp[0]=1;
        dp[1]=2;
        for(int i=2;i<=n;i++){
            dp[i]=0+dp[i-1];
            if(i>=2)
                dp[i]+=dp[i-2];
            dp[i]%=mod;
        }
        return (dp[n]%mod*dp[n]%mod)%mod;
        
    }
};