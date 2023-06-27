class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();int n=triangle.size();
        vector<vector<int>>dp(m,vector<int>(n+1,999999));
        
        dp[0][0]=triangle[0][0];
        
        for(int i=1;i<m;i++){
            for(int j=0;j<i+1;j++){
                int du=triangle[i][j]+dp[i-1][j];
                int lu=INT_MAX;
                if(j-1>=0)
                    lu=triangle[i][j]+dp[i-1][j-1];
                // cout<<du<<" "<<lu<<endl;
                dp[i][j]=min(du,lu);
            }
        }
        int ans=INT_MAX;
        for(auto i=0;i<n;i++)ans=min(ans,dp[m-1][i]);
        
        return ans;
    }
};