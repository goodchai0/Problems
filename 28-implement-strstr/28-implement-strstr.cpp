class Solution {
public:
    int strStr(string haystack, string needle) {
        int h=haystack.size()-1,n=needle.size()-1;
        
        for(int i=0;i<=h;i++)
        {
            if(haystack[i]==needle[0])
            {
                
                int pos=i;
                bool flag=0;
                for(int j=0;j<=n;j++)
                {
                    if(needle[j]==haystack[pos])pos++;
                    else {
                        flag=1;
                        break;
                    }
                }
                 if(flag==0)
                     return i;
            }         
        }
        return -1;
    }
};