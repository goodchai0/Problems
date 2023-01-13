class Solution {
public:
    
    int dfs(int currentNode,vector<vector<int>>&adjacentNodes,string &s,int &maxlength){
        int currentMax=0,secondMax=0;
        for(auto nextNode:adjacentNodes[currentNode]){
            int result=dfs(nextNode,adjacentNodes,s,maxlength);
            if(s[currentNode]==s[nextNode]){
                continue;
            }
            if(result>currentMax){
                secondMax=currentMax;
                currentMax=result;
            }
            else if(result > secondMax){
                secondMax=result;
            }
        }
        maxlength=max(maxlength,1+currentMax+secondMax);
        return 1+currentMax;
    }
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        int ans=1;
        
        vector<vector<int>>adj(n);
        
        for(int i=1;i<n;i++)
            adj[parent[i]].push_back(i);
        dfs(0,adj,s,ans);
        return ans;
    }
};