//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>>ans;
    void solve(int col,vector<int>&board,vector<int>&leftRow,vector<int>&upperDia,vector<int>&lowerDia,int n)
    {
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftRow[row]==0 && upperDia[row+col]==0 && lowerDia[n-1+col-row]==0){
                board.push_back(row+1);
                leftRow[row]=1;
                upperDia[row+col]=1;
                lowerDia[n-1+col-row]=1;
                solve(col+1,board,leftRow,upperDia,lowerDia,n);
                board.pop_back();
                leftRow[row]=0;
                upperDia[row+col]=0;
                lowerDia[n-1+col-row]=0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<int>board;
        vector<int>leftRow(n,0),upperDia(2*n-1,0),lowerDia(2*n-1,0);
        solve(0,board,leftRow,upperDia,lowerDia,n);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends