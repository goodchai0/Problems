class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
         if(grid.empty())return 0;
        int m=grid.size(),n=grid[0].size(),days=0,tot=0,cnt=0;
        queue<pair<int,int>>rotten;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)tot++;
                if(grid[i][j]==2)rotten.push({i,j});
            }
        }
        if(tot==0)return 0;
        if(rotten.size()==0)return -1;
        
        vector<pair<int, int>> dirs = {{1, 0},{-1, 0},{0, -1},{0, 1}};
        int ans=-1;
        while(!rotten.empty()){
            int size=rotten.size();
            while(size--){
                auto x=rotten.front();
                rotten.pop();
                for (auto [dx, dy] : dirs) {
                    int i = x.first + dx;
                    int j = x.second + dy;
                    if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 1) {
                        grid[i][j] = 2;
                        tot--;
                        rotten.push({i, j});
                    }
                }
            }
            ans++;
        }
        if (tot == 0)
            return ans;
        return -1;
    }
};