class Solution {
public:
    int removePalindromeSub(string s) {
        int n=s.length();
        if(!n)return 0;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=s[n-1-i])return 2;
            
        }
        return 1;
    }
};