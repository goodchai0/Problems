class Solution {
public:
    string helper(string s)
    {
        string s2="";
        //size=s.size()-1;
        for(int i=0;i<s.size();i++)
        {
            if('A'<=s[i] && s[i]<='Z') s2+=s[i]+32;
            else if('0'<=s[i] && s[i]<='9') s2+=s[i];
            else if(s[i]>=97 && s[i]<=122) s2+=s[i];
            
        }
        return s2;
        
    }
    bool isPalindrome(string s) {
        string s1=helper(s);
        cout<<s1;
        int i=0,j=s1.length()-1;
        while(i<=j)
        {
            if(s1[i++]!=s1[j--])
                return false;
            
        }
        return true;
    }
};