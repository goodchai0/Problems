//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long subarrayRanges(int n, vector<int> &nums) {
        // code here
        
        
        vector<int>v;
        vector<int>prevMin(n,-1),nextMin(n,n),prevMax(n,-1),nextMax(n,n);
        
        for(int i=0;i<n;i++){
            while(!v.empty() and nums[i]<=nums[v.back()])v.pop_back();
            if(!v.empty()) prevMin[i]=v.back();
            v.push_back(i);
        }
        v.clear();
        
        for(int i=n-1;i>=0;i--){
            while(!v.empty() and nums[i]<nums[v.back()])v.pop_back();
            if(!v.empty()) nextMin[i]=v.back();
            v.push_back(i);
        }
        v.clear();
        
        for(int i=0;i<n;i++){
            while(!v.empty() and nums[i]>=nums[v.back()])v.pop_back();
            if(!v.empty()) prevMax[i]=v.back();
            v.push_back(i);
        }
        v.clear();
        
        for(int i=n-1;i>=0;i--){
            while(!v.empty() and nums[i]>nums[v.back()])v.pop_back();
            if(!v.empty()) nextMax[i]=v.back();
            v.push_back(i);
        }
        long long sum=0;
        for(int i=0;i<n;i++){
            long long leftMin=i-prevMin[i];
            long long rightMin=nextMin[i]-i;
            long long leftMax = i - prevMax[i];
            long long rightMax = nextMax[i] - i;
            
            sum+=(leftMax*rightMax -leftMin*rightMin)*nums[i];
        }
        return sum;
 
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
        cout << obj.subarrayRanges(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends