class Solution {
public:
    string breakPalindrome(string palindrome) {
        bool flag=0;
        int n=palindrome.size();
        if(n<2){
            return "";
        }
        for(int i=0;i<n;i++){
            if(n&1 && n/2==i){
                continue;
            }
            //cout<<palindrome[i]<<endl;
            if(palindrome[i]!='a'){
                palindrome[i]='a';
                break;
            }
            cout<<i<<" "<<n-1<<endl;
            if(i==n-1){
                flag=1;
            }
        }
        
        if(flag==1){
            palindrome[n-1]='b';
        }
        
        return palindrome;
    }
};