//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> s;
    public:
       /*returns min element from stack*/
       int getMin(){
           int ans=-1;
           if(!s.empty()) ans=s.top();
           return ans;
           //Write your code here
       }
       
       /*returns poped element from stack*/
       int pop(){
           int ans=-1;
           if(!s.empty()){
               s.pop();
               ans=s.top();
               s.pop();
           }
           return ans;
           //Write your code here
       }
       
       /*push element x into the stack*/
       void push(int x){
           if(s.empty())
            {
                s.push(x);
                s.push(x);
            }
            else{
                minEle=min(s.top(),x);
                s.push(x);
                s.push(minEle);
            }
           //Write your code here
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends