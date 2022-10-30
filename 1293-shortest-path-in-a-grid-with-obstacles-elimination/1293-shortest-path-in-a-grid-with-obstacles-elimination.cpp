class Solution {
public:
    
    vector<vector<int>>dir{{1,0},{0,1},{-1,0},{0,-1}};
    bool isValid(int x,int y,vector<vector<int>>&grid){
        return (x>=0 && x<grid.size() && y>=0 && y<grid[0].size());
    }
    
    int solve(int x,int y,vector<vector<int>>&grid,int k ,vector<vector<vector<int>>>&dp){
        if(x==grid.size()-1 && y==grid[x].size()-1)
            return 0;
        if(dp[x][y][k]!=-1)return dp[x][y][k];
        
        dp[x][y][k]=1e7;
        for(int i=0;i<4;i++){
            int nx=x+dir[i][0];
            int ny=y+dir[i][1];
            
            if(isValid(nx,ny,grid)){
                if(grid[nx][ny]){
                    if(k>0){
                        dp[x][y][k]=min(dp[x][y][k],1+solve(nx,ny,grid,k-1,dp));
                    }
                }
                else
                    dp[x][y][k]=min(dp[x][y][k],1+solve(nx,ny,grid,k,dp));
                    
            }
        }
        
        return dp[x][y][k];
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size();int n=grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(k+1,-1)));
        int ans=solve(0,0,grid,k,dp);
        return ans>=1e7?-1:ans;
    }
};