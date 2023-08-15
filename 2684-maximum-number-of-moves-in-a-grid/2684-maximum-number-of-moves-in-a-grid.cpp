class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        
        vector<vector<int>>v(m,vector<int>(n,0));
        int level=0;
        int ans=INT_MIN;
        vector<pair<int,int>>dirs={{-1,1},{0,1},{1,1}};
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<m;i++){
            v[i][0]=1;
            q.push({1,{i,0}});
        }
            while(!q.empty()){
            // int level=0;
            auto x=q.front().second;
            auto cnt=q.front().first;
            q.pop();
            for(auto dir:dirs){
                int a=x.first+dir.first;
                int b=x.second+dir.second;
                // cout<<a<<" "<<b<<endl;
                if(a>=m || a<0 || b>=n|| b<0 )continue;
                else{
                    if(grid[a][b]<grid[x.first][x.second])continue;
                    if(v[a][b]==0 && grid[a][b]>grid[x.first][x.second]){
                        q.push({cnt+1,{a,b}});
                        v[a][b]=cnt+1;
                    }
                    // else if(v[a][b]!=0 && grid[a][b]>grid[x.first][x.second]){
                    //     q.push({max(cnt+1,v[a][b]),{a,b}});
                    // }
                }   
            }
            // cout<<cnt<<endl;
            ans=max(ans,cnt);
        }
        
        return ans-1;
    }
};