class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& triangle) {
        int m=triangle.size();int n=triangle[0].size();
        vector<vector<int>>dp(m,vector<int>(n+1,999999));
        
         for(int i=0;i<n;i++){
            dp[0][i]=triangle[0][i];
         }
        
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                int du=triangle[i][j]+dp[i-1][j];
                int lu=INT_MAX,ru=INT_MAX;
                if(j-1>=0)
                    lu=triangle[i][j]+dp[i-1][j-1];
                if(j+1<n)
                    ru=triangle[i][j]+dp[i-1][j+1];
                // cout<<du<<" "<<lu<<endl;
                dp[i][j]=min(du,min(ru,lu));
            }
        }
        int ans=INT_MAX;
        for(auto i=0;i<n;i++)ans=min(ans,dp[m-1][i]);
        
        return ans;
    
    }
};