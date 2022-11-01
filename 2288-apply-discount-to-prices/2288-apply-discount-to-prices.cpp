class Solution {
public:
    string discountPrices(string sentence, int discount) {
        string word;
        string ans="";
        stringstream ss(sentence);
        while(ss>>word){
            bool flag=false;
            for(int i=1;i<word.size();i++){
                if((word[i]-'0')>=0 && (word[i]-'0')<=9){
                    continue;
                }
                flag=true;
                break;
            }
            
            if(word[0]!='$' || flag || word.size()==1){
                ans+=word+" ";
                continue;
            }
            
            string s1=word.substr(1);
            long double no=stold(s1);
            long double x1=no;
            no=(long double)((discount*no)/100);
            no=(long double)(x1-no);
            
            string s2=to_string(no);
            
            int k=-1;
            for(int i=0;i<s2.size();i++){
                if(s2[i]=='.'){
                    k=i;
                    break;
                }
            }
            
            s2=s2.substr(0,k+3);
            ans+="$"+s2+" ";
        }
        ans.pop_back();
        return ans;
    }
};