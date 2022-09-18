class Solution {
public:
    
    void aux(vector<vector<int>>& grid, int row, int col, int newColor, int oldColor, vector<vector<bool>>& visited)
{ 
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size()|| visited[row][col] || grid[row][col]!=oldColor) return ;
        
        visited[row][col]=true;
        
        int count=0;
        
        if(row-1>=0 && grid[row-1][col]==oldColor) count++;
        if(col-1>=0 && grid[row][col-1]==oldColor) count++;
        if(row+1<grid.size() && grid[row+1][col]==oldColor) count++;
        if(col+1<grid[0].size() && grid[row][col+1]==oldColor) count++;
        
        if(row - 1 >= 0 && !visited[row - 1][col]) aux(grid, row - 1, col, newColor, oldColor, visited);
        if(col - 1 >= 0 && !visited[row][col - 1]) aux(grid, row, col - 1, newColor, oldColor, visited);
        if(row + 1 < grid.size() && !visited[row + 1][col]) aux(grid, row + 1, col, newColor, oldColor, visited);
        if(col + 1 < grid[0].size() && !visited[row][col + 1]) aux(grid, row, col + 1, newColor, oldColor, visited);
        
        
        if(count!=4 || row == 0 || col == 0 || row == grid.size() - 1 || col == grid[0].size() - 1) grid[row][col] = newColor;
        
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        
        aux(grid,row,col,color,grid[row][col],visited);
        
        return grid;
    }
};