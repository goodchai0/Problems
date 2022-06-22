class Solution {
public:
    
    unordered_map<string,vector<string>>adj;
    unordered_set<string>visited;
    
    void dfs(string& src,vector<string>& mergedAccounts)
    {
        visited.insert(src);
        mergedAccounts.push_back(src);
        for(auto & x:adj[src])
        {
            if(visited.count(x)==0)
                dfs(x,mergedAccounts);
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
       int n=accounts.size();
        vector<vector<string>>ans;
        
        for(int i=0;i<n;i++)
        {
            string firstEmail=accounts[i][1];
            
            for(int j=2;j<accounts[i].size();j++)
            {
                string email=accounts[i][j];
                adj[firstEmail].push_back(email);
                adj[email].push_back(firstEmail);
            }
        }
        for(int i=0;i<n;i++)
        {
            string accName=accounts[i][0];
            
            for(int j=1;j<accounts[i].size();j++)
            {
                string email=accounts[i][j];
                
                if(visited.find(email)==visited.end())
                {
                    vector<string>mergedAccounts;
                    dfs(email,mergedAccounts);
                    sort(mergedAccounts.begin(),mergedAccounts.end());
                    mergedAccounts.insert(mergedAccounts.begin(),accName);
                    ans.push_back(mergedAccounts);
                }
            }
        }
        return ans;
    }
};