//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        vector<int>ans;
        int n=asteroids.size();
        stack<int>s;
        
        
       for(int i=0; i<n; i++){
            if(asteroids[i] > 0 || s.empty()) s.push(asteroids[i]);
            else{
                while(!s.empty() && abs(asteroids[i]) > s.top() && s.top() > 0) s.pop();

                if(!s.empty() && abs(asteroids[i]) == s.top())s.pop();

                else if(s.empty() || s.top() < 0) s.push(asteroids[i]);
            }
        }
        
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends