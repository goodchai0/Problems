//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<long long>s;
        unordered_map<long long,long long>mp;
        vector<long long>v;
        for(long long i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]<=arr[i])s.pop();
            mp[i]=(s.empty())?-1:arr[s.top()];
            s.push(i);
        }
        for(auto i=0;i<n;i++){
            v.push_back(mp[i]);
        }
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends