class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int left=0,right=m-1,bottom=n-1,top=0;
        int s=m*n;
        int direction=1;
        vector<int>v;
        while(left<=right && top<=bottom)
        {
            for(int i=left;i<=right;i++)
                v.push_back(matrix[top][i]);
            top++;
            if(v.size()==s)
                break;
            for(int i=top;i<=bottom;i++)
                v.push_back(matrix[i][right]);
            right--;
            if(v.size()==s)
                break;
            for(int i=right;i>=left;i--)
                v.push_back(matrix[bottom][i]);
            bottom--;
            if(v.size()==s)
                break;
            for(int i=bottom;i>=top;i--)
                v.push_back(matrix[i][left]);
            left++;
            if(v.size()==s)
                break;

        }
        return v;
    }
    
};