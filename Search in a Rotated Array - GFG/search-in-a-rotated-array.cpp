//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int search(int nums[], int l, int h, int target){
       
        //cout<<h<<endl;
    
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[l]<=nums[mid])
            {
                if(target>=nums[l] && target<nums[mid])
                    h=mid-1;
                else
                    l=mid+1;
            }
            else
            {
                if(target>nums[mid] && target<=nums[h])
                   l=mid+1;
                else
                     h=mid-1;
            }
        }
        return -1;
    }
};


//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends