class Solution {
public:
    vector<string>ans;
    void generate(string digits,string arr[],int i,string s){
        
        if(i==digits.length()){
            ans.push_back(s);
            return;
        }
        if(i>=digits.length())return;
        
        string v=arr[digits[i]-'0'];
        for(int j=0;j<v.size();j++){
                if(v[j]!='0'){
                    s+=v[j];
                    generate(digits,arr,i+1,s);
                    s.pop_back();
                }
                
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0)return ans;
        string arr[10]={"0","0","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string s="";
        generate(digits,arr,0,s);
        return ans;
    }
};