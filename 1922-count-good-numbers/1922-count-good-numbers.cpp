#define mod 1000000007
class Solution {
public:
    long long mul(int n,long long int i){
        if(i==0)
            return 1;
        long long int temp=mul(n,i/2);
        
        if(i&1){
            return (((long long int)n)*(temp%mod)*(temp%mod))%mod;
        }
        else{
            return ((temp%mod)*(temp%mod))%mod;
        }
    }
   
    long long int countGoodNumbers(long long n) {
        long long ans=1;
        if(n&1){
            return (5*(mul(5,n/2)%mod)*(mul(4,n/2)%mod))%mod;
        }
        return ((mul(5,n/2)%mod)*(mul(4,n/2)%mod))%mod;
    }
};