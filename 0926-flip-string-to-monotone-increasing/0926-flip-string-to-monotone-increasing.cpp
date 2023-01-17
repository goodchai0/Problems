class Solution {
public:
    int memo[100001][2];
    
    int dp(string &s,int i,int j){
        if(i==s.size()){
            return 0;
        }
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        if(j==0){
            if(s[i]=='1'){
                return memo[i][j]=min(1+dp(s,i+1,0),dp(s,i+1,1));
            }else{
                return memo[i][j]=min(1+dp(s,i+1,1),dp(s,i+1,0));
            }
        }else{
            if(s[i]=='1'){
                return memo[i][j]=dp(s,i+1,1);
            }else{
                return memo[i][j]=1+dp(s,i+1,1);
            }
        }
    }
    int minFlipsMonoIncr(string s) {
        memset(memo,-1,sizeof(memo));
        return dp(s,0,0);
    }
};