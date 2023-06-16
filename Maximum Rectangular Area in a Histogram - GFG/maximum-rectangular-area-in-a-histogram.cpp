//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long height[], int n)
    {
        // Your code here
        // int n=height.size();
        vector<long long>s;
        vector<long long>leftSmall(n,-1),rightSmall(n,n);
        
        for(auto i=0;i<n;i++){
            while(!s.empty() && height[i]<=height[s.back()])s.pop_back();
            leftSmall[i]=(s.empty())?-1:s.back();
            s.push_back(i);
            // cout<<leftSmall[i]<<" ";
        }
        
        s.clear();
        for(auto i=n-1;i>=0;i--){
            while(!s.empty() && height[i]<height[s.back()])s.pop_back();
            rightSmall[i]=(s.empty())?n:s.back();
            s.push_back(i);
            // cout<<rightSmall[i]<<" ";
        }
        
        long long maxA=0;
        for(int i=0;i<n;i++){
            // cout<<rightSmall[i]-leftSmall[i]<<" ";
            maxA=max(maxA,height[i]*(rightSmall[i]-leftSmall[i]-1));
        }
        return maxA;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends