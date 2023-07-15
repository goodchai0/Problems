class Solution {
public:
    int findCircleNum(vector<vector<int>>& c) {
        int vertex=c.size();
        vector<vector<int>>g;
        for(int i=0;i<vertex;i++){
            vector<int>temp;
            for(int j=0;j<vertex;j++){
                if(c[i][j]==1)
                    temp.push_back(j);
            }
            if(!temp.empty())
                g.push_back(temp);
        }

        vector<bool>visited(vertex,false);
        int ans=0;
        queue<int>q;
        for(int i = 0; i < vertex; i++){
            if(!visited[i]){
                q.push(i);
                ans++;
                visited[i]=true;
                while(!q.empty()){
                    int f=q.front();
                    q.pop();
                    for(auto x:g[f]){
                      if (!visited[x]) {
                        visited[x]=true;
                        q.push(x);
                      }
                    }
                }
            }
        }
        return ans;
    }
};