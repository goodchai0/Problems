//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long int MOD=1e9+7;
    int sumSubarrayMins(int N, vector<int> &arr) {
        // code here
        int n=arr.size();
        stack<int>st;
        vector<int>left(n,0);
        vector<int>right(n,n);
        
        for(int i=0;i<n;i++){
            while(st.size() && arr[st.top()]>=arr[i])st.pop();
            if(st.size()) left[i] = i - st.top();
            else left[i]=i+1;
            st.push(i);
        }
        while(st.size()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(st.size() && arr[st.top()]>arr[i])st.pop();
            if(st.size()) right[i] = st.top()-i;
            else right[i]=n-i;
            st.push(i);
        }
        int res = 0;
        for(int i=0; i<n; i++)
        {
            long long prod = (left[i]*right[i])%MOD;
            prod = (prod*arr[i])%MOD;
            res = (res%MOD + prod)%MOD;
        }
        
        return res%MOD;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.sumSubarrayMins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends