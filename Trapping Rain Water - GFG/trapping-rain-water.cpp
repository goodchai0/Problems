//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        
        // code here
        long long left=0;
        long long right=n-1;
        long long lm=arr[0];
        long long rm=arr[n-1];
        long long res=0;
        while(left<=right){
            if(arr[left]<=arr[right]){
                if(arr[left]>=lm)lm=arr[left];
                else{
                    res+=lm-arr[left];
                }
                left++;
            }
            else{
                if(arr[right]>=rm)rm=arr[right];
                else{
                    res+=rm-arr[right];
                }
                right--;
            }
        }
        return res;
    }
    
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends