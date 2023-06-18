//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestOnes(int n, vector<int>& nums, int k) {
        // Code here
        int one,zero,l,r,ans;
        one=zero=l=r=ans=0;
        while(r<nums.size()){
            int x=nums[r];
            
            if(x==1)one++;
            if(x==0)zero++;
            if(zero>k){
                while(l<=r && nums[l]!=0)l++;
                l++;
                zero--;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.longestOnes(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends