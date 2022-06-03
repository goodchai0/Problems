class Solution {
public:
    vector<vector<int>>ans;
    void pascal(int numRows) {
        vector<int>temp(numRows+1,1);
        for(int i=1;i<numRows;i++)
        {
            int sum=ans[numRows-1][i-1]+ans[numRows-1][i];
            temp[i]=sum;
        }
        ans.push_back(temp);
    }
    vector<vector<int>> generate(int numRows) {
        for(int i=0;i<numRows;i++)
            pascal(i);
        return ans;
    }
    
};