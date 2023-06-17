class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>mp(256,-1);
        int l,r,ans;
        l=r=ans=0;
        while(r<s.length()){
            if(mp[s[r]]!=-1)
                l=max(mp[s[r]]+1,l);
            
            mp[s[r]]=r;
            ans=max(ans,r-l+1);
            r++;
            
        }
        return ans;
    }
};