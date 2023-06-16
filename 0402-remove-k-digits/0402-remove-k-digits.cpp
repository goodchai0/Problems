class Solution {
public:
    string removeKdigits(string num, int k) {
        string s="";
        for(auto x:num){
            while(k>0 && !s.empty() && s.back()>x ){
                s.pop_back();
                k--;
            }
            if(!s.empty() || x!='0'){
                s.push_back(x);
            }
        }
        while(k>0 && !s.empty()){
            k--;
            s.pop_back();
        }
        
        return s==""?"0":s;
    }
};