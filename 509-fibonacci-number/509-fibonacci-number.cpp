class Solution {
public:
    int fib(int n) {
        //vector<int>dp(n+1,0);
        int dp1=0;
        int dp2=1;
        if(n==0)
            return 0;
        for(int i=2;i<=n;i++)
        {
            int temp=dp2;
            dp2=dp1+dp2;
            dp1=temp;
            //cout<<dp2<<" ";
        }
        return dp2;
    }
};