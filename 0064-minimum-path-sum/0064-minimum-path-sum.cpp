// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size(); 
//         vector<vector<int> > sum(m, vector<int>(n, grid[0][0]));
//         for (int i = 1; i < m; i++)
//             sum[i][0] = sum[i - 1][0] + grid[i][0];
//         for (int j = 1; j < n; j++)
//             sum[0][j] = sum[0][j - 1] + grid[0][j];
//         for (int i = 1; i < m; i++)
//             for (int j = 1; j < n; j++)
//                 sum[i][j]  = min(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];
        
//         for (int i = 0; i < m; i++){
//             for (int j = 0; j < n; j++)
//                 cout<<sum[i][j];
//             cout<<endl;
//         }
            
//         return sum[m - 1][n - 1];
        
//     }
// };

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();int n=grid[0].size();
        vector<vector<long long>>dp(m,vector<long long>(n+1,0));
        
        if(n==1 && m==1)return grid[0][0];
        dp[0][0]=grid[0][0];
        for(int i=1;i<n;i++){
            dp[0][i]=grid[0][i]+dp[0][i-1];
        }
        for(int i=1;i<m;i++){
            dp[i][0]=grid[i][0]+dp[i-1][0];            
        }
        
       for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};