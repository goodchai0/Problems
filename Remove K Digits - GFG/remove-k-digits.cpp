//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string num, int k) {
        
        string s="";
        for(auto x:num){
            while(k>0 && !s.empty() && s.back()>x ){
                s.pop_back();
                k--;
            }
            if(!s.empty() || x!='0'){
                s.push_back(x);
            }
        }
        while(k>0 && !s.empty()){
            k--;
            s.pop_back();
        }
        
        return s==""?"0":s;
   
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
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends