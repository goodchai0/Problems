class Solution {
public:
    int divide(int dividend, int divisor) {
        long long t=0,q=0;
        long long n=abs((long long)dividend),x=abs((long long) divisor);
        long long sign=(dividend<0)^(divisor<0)?-1:1;
        
        for(long long i=31;i>=0;i--)
        {
            if(t+(x<<i)<=n)
            {
                t=t+(x<<i);
                q|=1LL<<i;
            }
        }
        if(sign<0)
        {
            q=-q;
        }
        return q>=INT_MAX||q<INT_MIN?INT_MAX:q;
    }
};