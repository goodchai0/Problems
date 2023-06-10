//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int xoR(int l){
        int x=l%4;
        if(x==0)return l;
        if(x==1)return 1;
        if(x==2)return l+1;
        if(x==3)return 0;
    }
    int findXOR(int l, int r) {
        // complete the function here
        return xoR(l-1)^xoR(r);
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    }
}
// } Driver Code Ends