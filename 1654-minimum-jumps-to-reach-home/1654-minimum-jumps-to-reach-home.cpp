class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int>st{forbidden.begin(),forbidden.end()};
        queue<pair<int,int>>q;
        
        q.push({0,0});
        st.insert(0);
        int steps=0;
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                int u=q.front().first;
                int f=q.front().second;
                q.pop();
                if(u==x)
                    return steps;
                int r=u+a,l=u-b;
                if(!f && l>=0 && !st.count(l)){
                    st.insert(l);
                    q.push({l,1});
                }
                if(r<=6000 && !st.count(r))
                {
                    st.insert(r);
                    q.push({r,0});
                }
            }
            steps++;
        }  return -1;
        
    }
  
};