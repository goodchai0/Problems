class Solution {
public:
    vector<string>v;
    void generate(int n,int i,int j,string &s){
        if(s.length()==2*n){
            v.push_back(s);
            return ;
        }
        if(i<n){
            s+="(";
            generate(n,i+1,j,s);
            s.pop_back();
        }
        
        if(j<i){
            s+=")";
            generate(n,i,j+1,s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        generate(n,0,0,s);
        return v;
    }
};