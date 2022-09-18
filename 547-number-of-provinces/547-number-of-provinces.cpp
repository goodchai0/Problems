class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>>adj(isConnected.size());
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected.size();j++){
                if(isConnected[i][j]==1)
                adj[i].push_back(j);
            }
        }
        
        vector<int>vis(isConnected.size(),0);
        
        queue<int>q;
        int count=0;
        for(int i=0;i<isConnected.size();i++){
            if(!vis[i]){
                count++;
                q.push(i);
                vis[i]=1;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(auto it:adj[node]){
                        if(!vis[it]){
                            vis[it]=1;
                            q.push(it);
                        }
                    }
                }
            }
        }
        return count;
    }
};