//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int binarysearch(int nums[], int n, int target) {
        int i=0;
        int j=n-1;
        while(i<j){
            int mid=(i+j)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]>target){
                j=mid;
            }
            else{
                i=mid+1;
            }
        }
        return (nums[i]==target)?i:-1;    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends