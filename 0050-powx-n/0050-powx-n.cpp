class Solution {
public:
    double pow(double x,int n){
        if(n==0)return 1/1.0;
        double ans=pow(x,n/2);
        if(n<=0){
            if(n&1){
                return ans*ans*(1/x);
            }
            else{
                return ans*ans;
            }
        }
        else{
            if(n&1){
                return ans*ans*x;
            }
            else{
                return ans*ans;
            }
        }
        
    }
    double myPow(double x, int n) {
        return pow(x,n);
    }
};