class Solution {
public:
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>>mp;
    vector<string>ans;
    
    void dfs(string s){
        auto &map=mp[s];
        while(!map.empty()){
            string to=map.top();
            map.pop();
            // cout<<to<<"-->";
            dfs(to);
            // cout<<to<<"<--";
        }
        ans.push_back(s);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto x:tickets)
        {
            mp[x[0]].push(x[1]);
        }
        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};