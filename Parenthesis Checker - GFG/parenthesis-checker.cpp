//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char>st;
        for(i:x){
            if(i=='('|| i=='{' || i=='[')
                st.push(i);
            else{
                    if(st.empty())return false;
                    char temp=st.top();
                    if(i=='}')
                    {
                        if(temp!='{')
                            return false;
                    }
                    if(i==')')
                    {
                        if(temp!='(')
                            return false;
                    }
                    if(i==']')
                    {
                        if(temp!='[')
                            return false;
                    }
                    st.pop();
            }
        }
        if(!st.empty())return false;
        return true;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends