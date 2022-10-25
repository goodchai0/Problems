class Solution {
public:
    int dp[310][3001];
    int helper(vector<int>&v,int i,int w){
        if(w==0)
            return 0;
        if(i>=v.size()||w<0)return INT_MAX;
        if(dp[i][w]!=-1) return dp[i][w];
        
        int take=helper(v,i,w-v[i]);
        if(take!=INT_MAX) take+=1;
        int skip=helper(v,i+1,w);
        
        return dp[i][w]=min(take,skip);
    }
    int minimumNumbers(int num, int k) {
        int x=k;
        vector<int>v;
        
        while(x<=num){
            if(x!=0)v.push_back(x);
            x=10+x;
        }
        
        memset(dp,-1,sizeof dp);
        int res = helper(v, 0, num);
        return res==INT_MAX?-1:res;
    }
};