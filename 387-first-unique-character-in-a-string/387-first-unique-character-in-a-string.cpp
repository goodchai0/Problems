class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,pair<int,int>>mp;
        int ans=INT_MAX;
        int i=0;
        for(auto x:s){
            mp[x].first++;
            mp[x].second=i;
            i++;
        }
        
        for(auto &[c,x]:mp){
            // cout<<c<<" "<<x.first<<" "<<x.second<<endl;
            if(x.first==1)
            {
                ans=min(ans,x.second);
            }
        }
        if(ans!=INT_MAX)return ans;
        else return -1;
    }
};