class Solution {
public:
    int calculate(string s) {
        int length=s.length();
        if(length==0)return 0;
        int curr=0,last=0,result=0;
        char sign='+';
        for(int i=0;i<length;i++)
        {
            char currChar=s[i];
            if(isdigit(currChar))
            {
                curr=(curr*10)+(currChar-'0');
            }
            if(!isdigit(currChar)&& !iswspace(currChar) ||i==length-1)
            {
                if(sign=='+' || sign == '-')
                {
                    result+=last;
                    last=(sign=='+')?curr:-curr;
                }
                else if(sign=='*')
                {
                    last=last*curr;
                }
                else if(sign =='/')
                {
                    last=last/curr;
                }
                sign=currChar;
                curr=0;
            }
        }
        result+=last;
        return result;
    }
};