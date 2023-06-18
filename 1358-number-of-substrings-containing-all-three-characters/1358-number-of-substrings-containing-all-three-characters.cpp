class Solution {
public:
    int numberOfSubstrings(string s) {
        int i,j,ans,cnt;
        map<int,int>mp;
        i=j=ans=cnt=0;
        while(j<s.length()){
            mp[s[j]]++;
            // if(mp.size()!=3){ans=0;}
            while(mp.size()==3){
                mp[s[i]]--;
                if(mp[s[i]]==0)
                {
                    mp.erase(s[i]);
                }
                i++;
                ans++;
            }
            cnt+=ans;
            j++;
        }
        return cnt;
    }
};