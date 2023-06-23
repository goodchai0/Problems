//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int n, vector<char> &tasks) {
        // code here
        priority_queue<int>pq;
        vector<int>mp(26,0);

        for(auto x:tasks)mp[x-'A']++;

        for(int i=0;i<26;i++){
            if(mp[i])pq.push(mp[i]);
        }

        int time=0;
        while(!pq.empty()){
            vector<int>remain;
            int cycle=n+1;
            while(cycle && !pq.empty()){
                int ma=pq.top();
                pq.pop();
                if(ma>1)remain.push_back(ma-1);
                time++;
                cycle--;
            }
            for(auto x:remain){
                pq.push(x);
            }
            if(pq.empty())break;
            time+=cycle;
        }
        return time;
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends