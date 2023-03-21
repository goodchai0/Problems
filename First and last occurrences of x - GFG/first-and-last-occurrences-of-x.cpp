//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int nums[], int n , int target )
{
    // code here
    int ans=-1,ans1=-1;
        int l=0,hi=n-1;
        while(l<=hi)
        {
            int mid=l-(l-hi)/2;
            if(nums[mid]==target){
                ans=mid;
                hi=mid-1;
            }
            else if(nums[mid]>target)
            {
                hi=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        
        l=0;hi=n-1;
        while(l<=hi)
        {
            int mid=l-(l-hi)/2;
            if(nums[mid]==target){
                ans1=mid;
                l=mid+1;
            }
            else if(nums[mid]>target)
            {
                hi=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        
        return {ans,ans1};
        
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends