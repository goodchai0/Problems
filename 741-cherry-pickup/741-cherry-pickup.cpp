class Solution {
public:
    
    int func(int r1,int c1,int r2,int n,int m,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
        
       int c2=r1+c1-r2;
        
        if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1)
        {
            return INT_MIN;
        }
        
        if(dp[r1][c1][r2]!=-1)
        {
            return dp[r1][c1][r2];
        }

        if(r1==n-1 && c1==n-1)
        {
            return grid[r1][c1];
        }
        
      int ans=grid[r1][c1];
      if(r1!=r2)
          ans+=grid[r2][c2];
          
      int temp=max(func(r1+1,c1,r2+1,n,m,grid,dp),func(r1,c1+1,r2,n,m,grid,dp));
      temp=max(temp,func(r1+1,c1,r2,n,m,grid,dp));
      temp=max(temp,func(r1,c1+1,r2+1,n,m,grid,dp));
          
      ans+=temp;
      
        return dp[r1][c1][r2]=ans;
    }
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
          vector < vector < vector < int >>> dp(n, vector < vector < int >> (m, vector < int
          > (m, -1)));

          return max(0,func(0, 0, 0, n, m, grid, dp));
    }
};