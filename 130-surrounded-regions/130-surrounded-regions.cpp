class Solution {
public:
    void check(vector<vector<char>>& grid,int i,int j)
    {
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size() ||grid[i][j]!='O')return ;
        grid[i][j]='#';
        check(grid,i+1,j);
        check(grid,i-1,j);
        check(grid,i,j-1);
        check(grid,i,j+1);
    }
    
    void solve(vector<vector<char>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j  < grid[0].size(); j++){
                if(grid[i][j]=='O' && (i==0|| j==0||i==grid.size()-1||j==grid[0].size()-1))
                {
                    check(grid,i,j);
                }
            }
        }
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j  < grid[0].size(); j++){
                if(grid[i][j]=='#')
                {
                    grid[i][j]='O';
                }
                else if(grid[i][j]=='O')
                    grid[i][j]='X';
            }
            
        }
        
    }
};