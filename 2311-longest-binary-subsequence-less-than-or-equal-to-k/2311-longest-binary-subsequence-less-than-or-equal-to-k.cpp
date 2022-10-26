class Solution {
public:
    int helper(int n,int size,int sum,string &s,vector<vector<int>>&dp){
        if(n<0)
            return 0;
        if(dp[n][size] != -1){
            return dp[n][size];
        }
        int no=helper(n-1,size,sum,s,dp);
        int yes=0;
        if((sum-(s[n]-'0')*pow(2,size))>=0){
            yes=1+helper(n-1,size+1,(sum-(s[n]-'0')*pow(2,size)),s,dp);
        }
        
        return dp[n][size]=max(no,yes);
        
    }
    int longestSubsequence(string s, int k) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(n-1,0,k,s,dp);
    }
};