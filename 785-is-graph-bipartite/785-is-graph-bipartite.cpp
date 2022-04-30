class Solution {
public:
    
    bool dfs(int i,vector<int>&color,vector<vector<int>>&graph)
    {
        
        for(auto x:graph[i])
        {
            if(color[x]==-1)
            {
                color[x]=1-color[i];
                if(dfs(x,color,graph)==false)
                    return false;
            }
            else if(color[x]==color[i])
            {
                return false;
            }
        }
        return true;
        
    }
    
    
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                color[i]=1;
                if(dfs(i,color,graph)==false)
                    return false;
            }
        }
        return true;
        
    }
};




// class Solution {
// public:
    
//     bool isBipartiteHelper(vector<vector<int>>& graph, vector<int>& color, int startNode){
        
//         bool ans = true;
//         int n = graph.size();
//         queue<int> q;        
//         int currentColor = -1;
//         q.push(startNode);
//         color[startNode] = currentColor;
        
//         while(!q.empty()){
            
//             int frontNode = q.front();            
            
//             for(int i = 0; i < graph[frontNode].size(); i++){
                
//                 if(color[graph[frontNode][i]] == 0){
                    
//                     q.push(graph[frontNode][i]);
//                     color[graph[frontNode][i]] = -1*color[frontNode];
                    
//                 }else if(color[graph[frontNode][i]] == color[frontNode]){
//                     return false;
//                 }
                
//             }
//             q.pop();
//             currentColor = -1*currentColor;
            
            
//         }
        
//         return true;
        
//     }
    
//     bool isBipartite(vector<vector<int>>& graph){
        
//         int n = graph.size();
//         int ans = true;
//         vector<int> color(n, 0);
        
//         for(int i = 0; i < n; i++){
            
//             if(color[i] == 0){
//                 ans = (ans && isBipartiteHelper(graph, color, i));
//                 if(!ans) break;
//             }
            
//         }
        
//         return ans;
        
//     }
    
    
// };