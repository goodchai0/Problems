//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> triangle)
    {
        int m=N;int n=N;
        vector<vector<int>>dp(m,vector<int>(n+1,-999999));
        
         for(int i=0;i<n;i++){
            dp[0][i]=triangle[0][i];
         }
        
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                int du=triangle[i][j]+dp[i-1][j];
                int lu=INT_MIN,ru=INT_MIN;
                if(j-1>=0)
                    lu=triangle[i][j]+dp[i-1][j-1];
                if(j+1<n)
                    ru=triangle[i][j]+dp[i-1][j+1];
                // cout<<du<<" "<<lu<<endl;
                dp[i][j]=max(du,max(ru,lu));
            }
        }
        int ans=INT_MIN;
        for(auto i=0;i<n;i++)ans=max(ans,dp[m-1][i]);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends