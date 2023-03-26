class Solution {
public:
    int ans=-1;
    
    void dfs(vector<vector<int>>&graph,vector<int>&vis,int node,int d,unordered_map<int,int>&mp)
    {
        vis[node]=1;
        mp[node]=d;
        for(auto x:graph[node]){
            if(vis[x]==0){
                dfs(graph,vis,x,d+1,mp);
            }else if(mp.count(x)){
                ans=max(ans,d-mp[x]+1);
            }
        }
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<vector<int>>graph(n+1);
        vector<int>vis(n+1,0);
        
        for(int i=0;i<n;i++){
            if(edges[i]!=-1){
                graph[i].push_back(edges[i]);
            }
        }
        
        for(int i=0;i<n;i++){
            unordered_map<int,int>mp;
            dfs(graph,vis,i,0,mp);
        }
        return ans;
    }
};