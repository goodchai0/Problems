//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long maxScore(vector<int> &cardPoints, int N, int k) {
        // code here
        int total=0;
        for(auto x:cardPoints)total+=x;
        int n=cardPoints.size();
        if(k==n)return total;
        int size=n-k;
        int l,r,ans,sum;
        l=r=sum=0;ans=INT_MAX;
        while(r<n){
            sum+=cardPoints[r];
            if(r-l+1==size){
                ans=min(ans,sum);
                sum-=cardPoints[l];
                l++;
            }
            r++;
        }
        return total-ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends