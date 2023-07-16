class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<pair<int, int>> dirs = {{1, 0},{-1, 0},{0, -1},{0, 1}};
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) q.push({i, j});
                else mat[i][j] = INT_MAX;
            }
        }
        
        while(!q.empty()){
            auto f=q.front(); q.pop();
            for (auto dir : dirs) {
                int x = f.first + dir.first, y = f.second + dir.second;
                if(x>=0 and x<m and y>=0 and y<n){
                    if(mat[x][y]>mat[f.first][f.second]+1){
                        mat[x][y]=mat[f.first][f.second]+1;
                        q.push({x, y});
                    }
                }
            }
        }
        return mat;
    }
};