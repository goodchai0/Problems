#include <string>   
class Solution {
public:
    string reverseVowels(string s) {
        string vowels="";
        int i=0;
        vector<int>idx;
        for(auto x:s){
            if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u'||x=='A'||x=='E'||x=='I'||x=='O'||x=='U')
            {
                vowels+=x;
                idx.push_back(i);
            }  
            i++;
        }
        
        reverse(vowels.begin(),vowels.end());
        
        for(int i=0;i<idx.size();i++){
            int x=idx[i];
            cout<<x;
            s[x]=vowels[i];
        }
        return s;
    }
};