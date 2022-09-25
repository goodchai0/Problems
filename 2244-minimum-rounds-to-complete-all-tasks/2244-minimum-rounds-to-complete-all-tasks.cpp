class Solution {
public:
    
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mp;
        int count=0;
        int m=0;
        for(auto x:tasks){
            mp[x]++;
            m=max(m,mp[x]);
        }
        vector<int> dp(m + 1, INT_MAX / 2);
        dp[0]=0;
        for(int i=2;i<=m;i++){
            if(i>=2) dp[i]=min(dp[i-2]+1,dp[i]);
            if(i>=3) dp[i]=min(dp[i-3]+1,dp[i]);
        }
        
        for(auto [x,y]:mp){
            if(dp[y]==INT_MAX/2) return -1;
            count+=dp[y];
        }
        
        return count;
    }
};