class Solution {
public:
    void dfs(vector<int>g[],vector<bool>&vis,int &ans,int i){
        vis[i]=true;
        ans++;
        for(auto x:g[i]){
            if(vis[x]==false){
                dfs(g,vis,ans,x);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>arr[n];
        for(int i=0;i<edges.size();i++){
            arr[edges[i][1]].push_back(edges[i][0]);
            arr[edges[i][0]].push_back(edges[i][1]);
        }
        vector<bool>vis(n,false);
        vector<int>temp;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                int ans=0;
                dfs(arr,vis,ans,i);
                temp.push_back(ans);
            }
        }
        
        long long res=0;
        
        for(int i=0;i<temp.size();i++){
            res+=(long long)(temp[i])*(long long)(n-temp[i]);
        }
        res/=2;
        return res;
    }
};