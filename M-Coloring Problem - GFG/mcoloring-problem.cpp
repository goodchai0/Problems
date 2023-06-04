//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    int color[20]={-1};
    bool isSafe(bool graph[101][101], int n,int i,int col){
        for(int k=0;k<n;k++)
            if(graph[i][k] && color[k]==col)return false;
        return true;
    }
    bool helper(bool graph[101][101], int m, int n,int i){
        if(i==n)return true;
        
        for(int col=0;col<m;col++){
            if(isSafe(graph,n,i,col)){
                color[i]=col;
                if(helper(graph,m,n,i+1))return true;;
                color[i]=-1;
            }
        }
        return false;
        
    }
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
                for(int i=0 ; i<n ; i++)    color[i]=-1 ; 

        return helper(graph,m,n,0);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends