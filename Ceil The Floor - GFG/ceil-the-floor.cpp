//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

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
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int v[], int n, int x) {
        
        // Your code here
        sort(v, v + n);
        int i=0;
        int j=n-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(v[mid]==x){
                return {x,x};
            }
            if(v[mid]>x){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        int floor,ceil;
        if(i-1<0){
            floor=-1;
        }
        else floor=(v[i-1]<=x)?v[i-1]:-1;
        if(i==n){
            ceil=-1;
        }
        else ceil=(v[i]>=x)?v[i]:-1;
        return {floor,ceil};
        
}