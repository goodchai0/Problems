//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        int x,y,l,r,cx,cy,ans;
        x=y=-1;
        l=r=cx=cy=ans=0;
        while(r<fruits.size()){
            int a=fruits[r];
            if(x==a || y==a){
                (a==x)?cx++:cy++;
            }
            else if(x==-1){
                x=a;
                cx++;
            }
            else if(y==-1){
                y=a;
                cy++;
            }
            else if(a!=x && a!=y){
                while(l<=r &&cy!=0 && cx!=0){
                    (fruits[l]==x)?cx--:cy--;
                    l++;
                }
                // cout<<l<<" "<<a<<endl;
                (cx==0)?(x=a,cx++):(cy++,y=a);
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends