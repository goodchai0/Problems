class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0;
        for(auto x:s){
            if(x==t[i]){
                i++;
            }
        }
        return t.size()-i;
    }
};