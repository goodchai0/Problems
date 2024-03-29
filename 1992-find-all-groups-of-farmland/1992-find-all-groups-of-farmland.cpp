class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size();
        int m=land[0].size();
        
        vector<vector<int>>res;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]==1){
                    if((i==0 || land[i-1][j]==0) && (j==0 || land[i][j-1]==0)){
                        int right=j;
                        int down=i;
                        
                        while(down+1<n && land[down+1][j]==1)down++;
                        while(right+1<m && land[i][right+1]==1)right++;
                        
                        res.push_back({i,j,down,right});
                    }
                }
            }
        }
        return res;
    }
};