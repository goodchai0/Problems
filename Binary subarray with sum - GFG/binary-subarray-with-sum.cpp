//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
  
    int sumtomost(vector<int>& arr, int target){
        int l,r,sum,ans;
        if(target<0)return 0;
        sum=ans=r=l=0;
        
        while(r<arr.size()){
            sum+=arr[r];
            while(sum>target){
                sum-=arr[l];
                l++;
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& arr, int N, int target){
        // code here
        return sumtomost(arr,target)-sumtomost(arr,target-1);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int target; 
        cin >> target;
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin >> arr[i];
        Solution obj;
        cout<<obj.numberOfSubarrays(arr, N, target)<<endl;
    }
    return 0;
}
// } Driver Code Ends