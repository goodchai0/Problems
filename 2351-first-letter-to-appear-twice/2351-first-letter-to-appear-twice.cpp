class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char,int>mp;
        char ans;
        for(auto x:s){
            mp[x]++;
            if(mp[x]==2)
            {
                ans=x;return x;
            }
        }
        return ans;
    }
};