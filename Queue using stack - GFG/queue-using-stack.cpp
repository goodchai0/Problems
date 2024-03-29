//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Queue {
    stack<int> input, output;
public:

    void enqueue(int x) {
        output.push(x);
    }

    int dequeue() {
        int n=output.size();
        while(n--){
            int y=output.top();
            output.pop();
            input.push(y);
        }
        int x=input.top(); 
        input.pop();
        n=input.size();
        while(n--){
            int y=input.top();
            input.pop();
            output.push(y);
        }
        return x;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Queue ob;

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            ob.enqueue(a);
        }
        else if(QueryType==2)
        {
            cout<<ob.dequeue()<<" ";

        }
        }
    cout<<endl;
    }
}

// } Driver Code Ends