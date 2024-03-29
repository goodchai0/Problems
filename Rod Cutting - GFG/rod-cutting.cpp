//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int f(int i,int price[],int rodLen,int n,vector<vector<int>>& dp){
        if(rodLen==0)return 0;
        if(i==n)return -1e9;
        
        if(dp[i][rodLen]!=-1)return dp[i][rodLen];
        
        int notake=f(i+1,price,rodLen,n,dp);
        int take=-1e9;
        if(rodLen>=i+1)
        take=price[i]+f(i,price,rodLen-(i+1),n,dp);
        
        return dp[i][rodLen]=max(take,notake);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(0,price,n,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends