class Solution {
public:
    int tribonacci(int n) {
        if(n==0)return 0;
        
        if(n<3) return 1;
        
        if(n==3)return 2;
        
        
       int nn,n1=1,n2=1,n3=2;
        
        for(int i=3;i<n;i++){
            nn=n1+n2+n3;
            n1=n2;
            n2=n3;
            n3=nn;
 
        }
        return nn;
    }
};