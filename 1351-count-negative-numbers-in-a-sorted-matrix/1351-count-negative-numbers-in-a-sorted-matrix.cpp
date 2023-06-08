class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        int m=0,count=0;
        for(int i=grid[0].size()-1;i>=0 && m<grid.size();)
        {
            if(grid[m][i]<0)
            {
                count=count+grid.size()-m;
                i--;
            }
            else{
                m++;
            }
        }
        return count;
        
        
    }
};