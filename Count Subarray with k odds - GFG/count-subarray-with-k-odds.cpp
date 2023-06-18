//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
      int atMost(vector<int>&nums,int k){
          int i,j,sum,ans;
          i=j=sum=ans=0;
          
          while(j<nums.size()){
              sum+=nums[j];
              
              while(sum>k){
                  sum-=nums[i];
                  i++;
              }
              ans+=j-i+1;
              j++;
          }
          return ans;
      }

    int countSubarray(int n, vector<int>& nums, int k) {
        // Code here
        for(auto &num:nums)
            if(num%2)
                num=1;
            else
                num=0;
        return atMost(nums,k)-atMost(nums,k-1);

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
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends