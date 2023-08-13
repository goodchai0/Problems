class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        vector<int>row(n,1),col(n,1);
        int nrow=n,ncol=n;
        long long int ans=0;
        for(int i=queries.size()-1;i>=0;i--){
            if(queries[i][0]==0 && row[queries[i][1]]){ans+=queries[i][2]*ncol; row[queries[i][1]]=0; nrow--; }
            if(queries[i][0]==1 && col[queries[i][1]]){ans+=queries[i][2]*nrow; col[queries[i][1]]=0; ncol--; }
        }
        return ans;
    }
};