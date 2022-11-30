class Solution {
public:
    unordered_map<int,int>mp;
    set<int>s;
    bool uniqueOccurrences(vector<int>& arr) {
        
        for(auto x:arr){
            mp[x]++;
        }
        
        for(auto [x,y]:mp){
            if(s.find(y)==s.end())
                s.insert(y);
            else 
                return false;
        }
        return true;
    }
};