class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<vector<int>>graph(26);
        
        for(auto eqn:equations)
        {
            if(eqn.substr(1,2) == "==")
            {
                int x=eqn[0]-'a';
                int y=eqn[3]-'a';
                graph[x].push_back(y);
                graph[y].push_back(x);
            }
        }
        
        vector<int>color(26,0);
        
        int t=0;
        for(int start=0;start<26;start++)
        {
            if(color[start]==0)
            {
                t++;
                stack<int>st;
                st.push(start);
                while(!st.empty())
                {
                    int node=st.top();
                    st.pop();
                    for(auto nei:graph[node])
                    {
                        if(color[nei]==0)
                        {
                            color[nei]=t;
                            st.push(nei);
                        }
                    }
                }
            }
        }
        for(auto eqn:equations)
        {
            if(eqn.substr(1,2) == "!=")
            {
                int x=eqn[0]-'a';
                int y=eqn[3]-'a';
                if(x==y||color[x]!=0 && color[x]==color[y])
                    return false;
            }
        }
        return true;
    }
};