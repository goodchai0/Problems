class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>> m(col,vector<int>(row,0));
        
        for(int i=0;i<col;i++)
            for(int j=0;j<row;j++)
                swap(matrix[j][i],m[i][j]);
        
        return m;
    }
};