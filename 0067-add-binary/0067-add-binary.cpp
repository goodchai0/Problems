class Solution {
public:
    string addBinary(string a, string b) {
        
        int z=a.length();
        int y=b.length();
         string ans="";
        int carry=0,x;
        int num1,num2;
        // for(int i=0;i<z;i++)
        //     cout<<a[i]<<i<<" ";
        // cout<<endl;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        for(int i=0;i<max(z,y);i++)
        {
            if(i<=z)
            {
               if(a[i]=='1')
                num1=1 ;
                else num1=0; 
            }
            
            
            if(i<=y)
            {
               if(b[i]=='1')
                num2=1 ;
                else num2=0; 
                
            }
            
            
            //cout<<num1<<" "<<num2<<endl;
            x=(num1+num2+carry)%2;
            carry=(num1+num2+carry)/2;
            
            if(x==1)
                ans+='1';
            else if(x==0)
                ans+='0';
        }
        if(carry!=0)
            ans+='1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};