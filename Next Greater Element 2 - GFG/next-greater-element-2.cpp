//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> nextGreaterElement(int N, vector<int>& nums) {
        // code here
        stack<int>s;
        map<int,int>mp;
        for(int i=2*nums.size()-1;i>=0;i--){
            while(!s.empty() && nums[s.top()]<=nums[i%nums.size()])s.pop();
            mp[i%nums.size()]=(s.empty())?-1:nums[s.top()];
            s.push(i%nums.size());
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(mp[i]);
        }
        return ans;
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
        vector<int> ans = obj.nextGreaterElement(N, arr);
        for (auto &it : ans) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends