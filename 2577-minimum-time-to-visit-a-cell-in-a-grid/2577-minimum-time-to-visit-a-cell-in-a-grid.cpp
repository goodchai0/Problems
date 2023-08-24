class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=INT_MAX;
        vector<vector<int>>dirs{{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<bool>>visited(m,vector<bool>(n,0));
        
        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;
        pq.push({0,0,0});
        visited[0][0]=1;
        // do initial explore
        if(grid[1][0]<=1){
            pq.push({1, 1, 0});
            visited[1][0]=true;
        }
        if(grid[0][1]<=1){
            pq.push({1, 0, 1});
            visited[0][1]=true;
        }
        
        
        if(pq.size()==1)return -1;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            
            
            int time=curr[0],i=curr[1],j=curr[2];
            
            if(i==m-1 && j==n-1)ans=min(ans,time);
            
            for(auto x:dirs){
                int r=i+x[0];
                int c=j+x[1];
                
                if(r>=0 && r<m && c>=0 && c<n && visited[r][c]==0){
                    if(time+1>=grid[r][c]){
                        pq.push({time+1,r,c});
                    }
                
                    else{
                        int diff=grid[r][c]-time;
                        if(diff%2==0){
                            pq.push({grid[r][c]+1,r,c});
                        }else{
                            pq.push({grid[r][c],r,c});
                        }
                    }
                    visited[r][c]=1;
                }
            }
        }
        return ans;
    }
};