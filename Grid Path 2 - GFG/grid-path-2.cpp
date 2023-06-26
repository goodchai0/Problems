//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int totalWays(int m, int n, vector<vector<int>>& obstacleGrid) {
        // Code here
        int MOD=1e9+7;
        vector<vector<long long>>dp(m,vector<long long>(n,0));
        if(obstacleGrid[0][0]==1)return 0;
        for(int i=0;i<n;i++){
            if(obstacleGrid[0][i]==0)dp[0][i]=1;
            if(obstacleGrid[0][i]==1)break;
        }
        for(int i=0;i<m;i++){
            if(obstacleGrid[i][0]==0)dp[i][0]=1;
            if(obstacleGrid[i][0]==1)break;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]!=1){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                    dp[i][j]%=MOD;
                }
                else{
                     dp[i][j]=0;
                }
            }
        }
        return dp[m-1][n-1]%MOD;

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends