class Solution {
public:
    int divide(int dividend, int divisor) {
        long long sign = ((dividend<0 && divisor>=0) || (dividend>=0 && divisor<0))?-1L:1L;
        long long dividend_=abs((long long)dividend);
        long long divisor_=abs((long long)divisor);
        long long temp=0,quo=0;
        for(long long i=31;i>=0;i--){
            if(temp+(divisor_<<i)<=dividend_){
                temp+=(divisor_<<i);
                quo+=(1LL<<i);
            }
        }
        if(sign<0)
        {
            quo=-quo;
        }
        cout<<INT_MAX;
        return quo>=INT_MAX||quo<INT_MIN?INT_MAX:quo;
    }
};