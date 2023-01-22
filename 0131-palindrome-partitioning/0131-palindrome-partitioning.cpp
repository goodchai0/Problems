class Solution {
public:
    bool ispalindrome(string s,int index,int i){
        while(index<=i){
            if(s[i]!=s[index])return false;
            index++;
            i--;
        }
        return true;
    }
    void solve(string s,int index,vector<vector<string>>&ans,vector<string>&ds){
        
        if(index==s.size()){
            ans.push_back(ds);
        }
        
        for(int i=index;i<s.size();i++){
            if(ispalindrome(s,index,i)){
                ds.push_back(s.substr(index,i-index+1));
                solve(s,i+1,ans,ds);
                ds.pop_back();
                
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>ds;
        solve(s,0,ans,ds);
        return ans;
    }
};