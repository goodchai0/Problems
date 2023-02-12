class Solution {
public:
    long long ans=0;
    long long dfs(int src,int seats,vector<bool>&visited,vector<vector<int>>&graph){
        
        visited[src]=true;
        long long count=1;
        for(auto adj:graph[src]){
            if(visited[adj]){
                continue;
            }
            count+=dfs(adj,seats,visited,graph);
        }
        
        if(count<=seats){ans+=1;}
        else{
            long long cars=ceil(count/(seats*1.0));
            ans+=cars;
        }
        return count;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size();
        vector<vector<int>>graph(n+1);
        for(auto it:roads){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);

        }
        vector<bool>visited(n+1,false);
        visited[0]=true;
        for(auto it:graph[0]){
            dfs(it,seats,visited,graph);
        }
        return ans;
    }
};