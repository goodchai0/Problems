class Solution {
public:
    vector<string>grid;
    vector<vector<vector<bool>>>visited;
    int height,width;
    bool inside(int row,int col)
    {
        int height=grid.size();
        int width=grid[0].size();
        return 0<=row && row<height && 0<=col && col<width;
    }
    void dfs(int row,int col,int type)
    {
        if(!inside(row,col) || visited[row][col][type])
            return ;
        visited[row][col][type]=true;
        if(type==0){
            dfs(row-1,col,2);
        }
        else if(type==1)
        {
            dfs(row,col+1,3);
        }
        else if(type==2)
        {
            dfs(row+1,col,0);
        }
        else if(type==3)
        {
            dfs(row,col-1,1);
        }
        if(grid[row][col]!='/')
        {
            dfs(row,col,type^1);
        }
        if(grid[row][col]!='\\')
        {
            dfs(row,col,type^3);
        }
    }
    int regionsBySlashes(vector<string>& _grid) {
        grid=_grid;
        height=grid.size();
        width=grid[0].size();
        visited.clear();
        visited.resize(height,vector<vector<bool>>(width,vector<bool>(4)));
        
        int region=0;
        for(int row=0;row<height;row++)
        {
            for(int col=0;col<width;col++)
            {
                for(int type=0;type<4;type++)
                {
                    if(!visited[row][col][type])
                    {
                        dfs(row,col,type);
                        region++;
                    }
                }
            }
        }
        return region;
            
    }
};