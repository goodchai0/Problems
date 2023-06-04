//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string>ans;
    void helper(vector<vector<int>> &m, int n,int i,int j,string &s){
        if(i<0 || i>=n || j<0 || j>=n || m[i][j]==0 )
            return;
        if(i==n-1 && j==n-1){
            // cout<<s<<endl;
            ans.push_back(s);
            return;
        }
        s+="D";
        m[i][j]=0;
        helper(m,n,i+1,j,s);
        s.pop_back();
        s+="U";
        helper(m,n,i-1,j,s);
        s.pop_back();
        s+="L";
        helper(m,n,i,j-1,s);
        s.pop_back();
        s+="R";
        helper(m,n,i,j+1,s);
        s.pop_back();
        m[i][j]=1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        string s="";
        if(m[0][0]==0)return ans;
        helper(m,n,0,0,s);
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
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends