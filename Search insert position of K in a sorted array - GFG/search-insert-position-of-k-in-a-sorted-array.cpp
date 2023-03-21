//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int>v, int n, int x)
    {
        // code here
        // Your code here
        int i=0;
        int j=n-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(v[mid]==x)return mid;
            if(v[mid]>x){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        // cout<<i;
        // return i;
        return (v[i]>x)?i:i;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends