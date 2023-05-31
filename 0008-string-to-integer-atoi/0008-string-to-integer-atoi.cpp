class Solution {
public:
    int myAtoi(string s) {
        double ans=0;
        int flag=0;
        int i=0;
            while(s[i]==' '){
                i++;
            }
            if(s[i]=='-'){
                flag=1;
                i++;
            }
            else if(s[i]=='+'){
                flag=0;
                i++;
            }
            if('0'<=s[i] && s[i]<='9'){
                while('0'<=s[i] && s[i]<='9'){
                    ans=ans*10+(s[i]-'0');
                    i++;
                }
            }
        if(flag==1)
            ans=-1*ans;
        ans = (ans > INT_MAX) ? INT_MAX : ans;
        ans = (ans < INT_MIN) ? INT_MIN : ans;
        
        return int(ans);
        
    }
};