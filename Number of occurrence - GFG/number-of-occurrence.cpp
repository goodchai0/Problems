//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int nums[], int n, int target) {
	    int ans=-1,ans1=-1;
        int l=0,hi=n-1;
        bool flag=false;
        while(l<=hi)
        {
            int mid=l-(l-hi)/2;
            if(nums[mid]==target){
                ans=mid;
                hi=mid-1;
                flag=true;
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
        if(flag)
            return ans1-ans+1;
        return 0;
        
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends