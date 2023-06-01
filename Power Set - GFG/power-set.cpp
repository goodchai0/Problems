//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		vector<string>ans;

	    void generate(string s,int i,string v){
	        if(i==s.length()){
	            if(v!="")
	                ans.push_back(v);
	            return;
	        }
	        v+=s[i];
	        generate(s,i+1,v);
	        v.pop_back();
	        generate(s,i+1,v);
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    string v="";
		    generate(s,0,v);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends