// class Solution {
// public:
//     int mod=1e9+7;
//     int helper(int s,int end,int k,vector<vector<int>>&dp){
//         if(k==0 && s==end){
//             return 1;
//         }
//         if(k<=0)return 0;
//         if(dp[s+1000][k]!=-1)
//         {
//             return dp[s+1000][k];
//         }
        
//         int l=helper(s+1,end,k-1,dp);
//         int r=helper(s-1,end,k-1,dp);
        
//         return dp[s+1000][k]=(r+l)%mod;
//     }
    
//     int numberOfWays(int startPos, int endPos, int k) {
//         int count=0;
//         vector<vector<int>>dp(3000,vector<int>(k+1,-1));
//         //3000 to shift the index , so that we can form a dp table of positive indexes
       
//         return helper(startPos,endPos,k,dp)%mod;
//     }
// };



class Solution {
public:
    int mod=1e9+7;
    int numberOfWays(int startPos, int endPos, int k) {
        
        int start=0;
        int end=0;
        if(startPos<endPos){
            start=startPos;
            end=endPos;
        }else{
            start=endPos;
            end=startPos;
        }
        
        end=(end-start)+k;
        start=k;
        int n=2*k+(end-start)+2;
        
      vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        
        dp[end][0] = 1;
        
        for(int j = 1; j <= k; j++) {
            for(int i = 1; i < n; i++) {
                dp[i][j]=dp[i+1][j-1]%mod;
                dp[i][j]+=dp[i-1][j-1]%mod;
                dp[i][j]%mod;
            }
        }
        return dp[start][k]%mod;
    }
};























