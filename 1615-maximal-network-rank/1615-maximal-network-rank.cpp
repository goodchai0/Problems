class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<int>>mp;
        set<pair<int,int>>s;
        for(auto x:roads){
            mp[x[0]].push_back(x[1]);
            mp[x[1]].push_back(x[0]);
            s.insert({x[0],x[1]});
            s.insert({x[1],x[0]});
        }
        int ans=INT_MIN;
        for(auto x:roads){
            ans=max(ans,int(mp[x[1]].size()+mp[x[0]].size()-1));
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if((s.count({i,j})>0 || s.count({j,i})>0 ||i==j))continue;
                else ans=max(ans,int(mp[i].size()+mp[j].size()));
                // cout<<i<<" "<<j<<endl;
                
            }
        }
        return ans;
    }
};