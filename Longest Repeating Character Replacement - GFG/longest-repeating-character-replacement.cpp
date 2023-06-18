//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string s, int k) {
        // code here
        int l,r,ans,currL;
        l=r=ans=currL=0;
        unordered_map<int,int>mp;
        int maxR=0;
        while(r<s.length()){
            mp[s[r]]++;
            maxR=max(maxR,mp[s[r]]);
            currL=r-l+1;
            if(currL-maxR>k){
                mp[s[l]]--;
                l++;
                currL--;
            }
            currL=r-l+1;
            ans=max(ans,currL);
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
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends