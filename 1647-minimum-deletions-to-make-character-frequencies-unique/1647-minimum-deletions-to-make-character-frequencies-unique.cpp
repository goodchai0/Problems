class Solution {
public:
    int minDeletions(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++)
            mp[s[i]]++;
        int ans=0;
        
        set<int>st;
        
        for(auto i:mp)
        {
            while(st.find(i.second)!=st.end())
            {
                i.second--;ans++;
            }
            if(i.second>0)
                st.insert(i.second);
        }
        return ans;
    }
};