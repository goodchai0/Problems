class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int c=grid[sr][sc];
        grid[sr][sc]=-1;
        int m=grid.size(),n=grid[0].size();
        vector<pair<int, int>> dirs = {{1, 0},{-1, 0},{0, -1},{0, 1}};
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            for(auto y:dirs){
                int i = x.first + y.first;
                int j = x.second + y.second;
                if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] ==c ) {
                    grid[i][j] = -1;
                    q.push({i, j});
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==-1)grid[i][j]=color;
            }
        }
        return grid;
    }
};