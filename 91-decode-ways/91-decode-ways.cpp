class Solution {
public:
    vector<int>dp;
    int numDecodings(string s) {
        dp.resize(s.size());
        dp.assign(s.size(),-1);
        return nways(0,s);
    }
    
    int nways(int i,string s)
    {
        if(i>=s.size())
            return 1;
        else if(s[i]=='0')
            return 0;
        if(i==s.size()-1)return 1;
        if(dp[i]!=-1)
            return dp[i];
        if(s[i]=='1' || (s[i]=='2'&& (s[i+1]>=48 && s[i+1]<=54)))
          return  dp[i]=nways(i+1,s)+ nways(i+2,s);
        else
           return dp[i]=nways(i+1,s);
     
    }
};