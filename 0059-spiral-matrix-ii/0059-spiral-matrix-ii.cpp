class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,1));
        int left=0,right=n-1,top=0,down=n-1,index=1;
        
        while(left<=right && top<=down)
        {
            for(int j=left;j<=right;j++)
            {
                ans[top][j]=index;
                index++;
            }
            top++;
            for(int j=top;j<=down;j++)
            {
                ans[j][right]=index;
                index++;
            }
            right--;
            for(int j=right;j>=left;j--)
            {
                ans[down][j]=index;
                index++;
            }
            down--;
            for(int j=down;j>=top;j--)
            {
                ans[j][left]=index;
                index++;
            }
            left++;
        }
        return ans;
    }
};