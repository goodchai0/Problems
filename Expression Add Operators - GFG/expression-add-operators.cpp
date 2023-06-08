//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  vector<string>ans;
    void dfs(string &num , int target , int index , string path , long int res , long int prev){
        if(index==num.length()){
            if(res==target){
                ans.push_back(path);return;
            }
        }
        
        string temp="";
        long int tempNum=0;
        for(int i=index;i<num.length();i++){
            temp+=num[i];
            tempNum=(tempNum*10)+num[i]-'0';
            if(temp.size()>1 && temp[0]=='0')return;
            if(index==0){
                dfs(num,target,i+1,temp,tempNum,tempNum);
            }else{
                dfs(num,target,i+1,path+"+"+temp,res+tempNum,tempNum);
                dfs(num,target,i+1,path+"-"+temp,res-tempNum,-tempNum);
                dfs(num,target,i+1,path+"*"+temp,(res-prev)+(prev*tempNum),tempNum*prev);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        // code here
        dfs(num,target,0,"",0,0);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int target;
        string S;
        cin >> S >> target;

        Solution obj;
        vector<string> ans = obj.addOperators(S, target);
        sort(ans.begin(), ans.end());
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends