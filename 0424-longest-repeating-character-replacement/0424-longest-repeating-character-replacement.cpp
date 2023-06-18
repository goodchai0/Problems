class Solution {
public:
    int characterReplacement(string s, int k) {
        int l,r,ans,currL;
        l=r=ans=currL=0;
        unordered_map<int,int>mp;
        int maxR=0;
        while(r<s.length()){
            mp[s[r]]++;
            maxR=max(maxR,mp[s[r]]);
            currL=r-l+1;
            if(currL-maxR>k){
                mp[s[l]]--;
                l++;
                currL--;
            }
            currL=r-l+1;
            ans=max(ans,currL);
            r++;
        }
        return ans;
    }
};