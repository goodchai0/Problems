//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

    int search(vector<int>nums,int m){
        int i=0;
        int j=m-1;
        int ans=m;
        // for(auto x:nums)cout<<x<<" ";
        while(i<=j){
            int mid=(i+j)/2;
            // cout<<mid<<" ";
            if(nums[mid]==1){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        // cout<<ans<<endl;
        int count=m-ans;
        return count;
    }
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	   int ans1=0;
	    int ans=0;
	    int result;
	    for(int i=0;i<n;i++){
	        result=search(arr[i],m);
	        if(ans<result){
	            ans=result;
	            ans1=i;
	        }
	    }
	    
	    return ans!=0?ans1:-1;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends