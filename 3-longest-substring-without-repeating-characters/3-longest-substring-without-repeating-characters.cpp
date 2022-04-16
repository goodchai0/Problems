class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>mp(256,-1);
        
        int left=0,right=0;
        int len=s.length();
        int ans=0;
        while(right<len)
        {
            if(mp[s[right]]!=-1)
                left=max(left,mp[s[right]]+1);
            
            mp[s[right]]=right;
            ans=max(right-left+1,ans);
            right++;
        }
        return ans;
    }
};