class Solution {
public:
    
    void dfs(vector<vector<int>>& graph,vector<bool>&vis,int start){
        vis[start]=true;
        for(auto x:graph[start]){
            if(!vis[x]){
                dfs(graph,vis,x);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n>connections.size()+1)return -1;
        
        vector<vector<int>>graph(n);
        for(auto x:connections){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        int component=0;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                component++;
                dfs(graph,vis,i);
            }
        }
        return component-1;
        
    }
};