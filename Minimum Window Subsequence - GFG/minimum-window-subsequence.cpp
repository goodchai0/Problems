//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string minWindow(string s, string t) {
        // Write your Code here    string smallestWindow (string s, string t)
    
        // Your code here
        
        int m=s.size();
        int n=t.size();
        string str;
        int res=INT_MAX;
        // unordered_map<char,int>mp;
        int i,j,k,count;
        i=j=k=count=0;
        while(j<m && k<n){
            if(s[j]==t[k])k++;
            
            if(k==t.length()){
                i=j;
                k=t.length()-1;
                while(i>=0 && k>=0){
                    if(s[i]==t[k]){
                        k--;
                    }
                    i--;
                }
                i++;
                if(res>j-i+1){
                    res=j-i+1;
                    str=s.substr(i,j-i+1);
                }
                j=i+1;k=0;
            }
            j++;
        }

    return str;
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string str1, str2;
        cin >> str1 >> str2;

        Solution obj;
        cout << obj.minWindow(str1, str2) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends