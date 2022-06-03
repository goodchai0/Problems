class NumMatrix {
public:
    vector<vector<int>>dp;
    NumMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int>v;
        for(int i=0;i<=m;i++)
        {
            v.push_back(0);
        }
        for(int i=0;i<=n;i++)
        {
            dp.push_back(v);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                dp[i+1][j+1]=mat[i][j]+dp[i][j+1]+dp[i+1][j]-dp[i][j];
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1]-dp[row2+1][col1]-dp[row1][col2+1]+dp[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */