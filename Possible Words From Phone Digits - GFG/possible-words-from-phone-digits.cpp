//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    vector<string>ans;
    void generate(int digits[],string arr[],int i,string s,int N){
        
        if(i==N){
            ans.push_back(s);
            return;
        }
        if(i>=N)return;
        
        string v=arr[digits[i]];
        for(int j=0;j<v.size();j++){
                if(v[j]!='0'){
                    s+=v[j];
                    generate(digits,arr,i+1,s,N);
                    s.pop_back();
                }
                
        }
    }
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int digits[], int N)
    {
        //Your code here
        if(N==0)return ans;
        string arr[10]={"0","0","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string s="";
        generate(digits,arr,0,s,N);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends