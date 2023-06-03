class Solution {
public:
    bool isPalindrome(string s,int index,int i){
        while(index<=i){
            if(s[i]!=s[index])return false;
            index++;
            i--;
        }
        return true;
    }
    vector<vector<string>>ans;
    void generate(string s,vector<string>&v,int i){
        if(i==s.length()){
            ans.push_back(v);
            return;
        }
        for(int k=i;k<s.length();k++){
            if(isPalindrome(s,i,k)){
                v.push_back(s.substr(i,k-i+1));
                generate(s,v,k+1);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>v;
        generate(s,v,0);
        return ans;
    }
};