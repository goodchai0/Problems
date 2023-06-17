//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s){
        //code
        vector<int>mp(256,-1);
        int l,r,ans;
        l=r=ans=0;
        while(r<s.length()){
            if(mp[s[r]]!=-1)
                l=max(mp[s[r]]+1,l);
            
            mp[s[r]]=r;
            ans=max(ans,r-l+1);
            r++;
            
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends