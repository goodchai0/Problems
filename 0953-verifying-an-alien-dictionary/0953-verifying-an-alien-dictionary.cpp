class Solution {
public:
    int _map[26];
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0;i<order.length();i++){
            _map[order[i]-'a']=i;
        }
        // cout<<words.size();
        for(int i=0;i<words.size()-1;i++){
            cout<<words[i]<<" "<<words[i+1]<<endl;
            if(!compare(words[i],words[i+1]))return false;
        }
        return true;
    }
    
    
    bool compare(string &s1,string &s2){
        int j=0;
        while(j<s1.length() && j<s2.length()){
            if(s1[j]==s2[j])j++;
            else if(_map[s1[j]-'a']<_map[s2[j]-'a'])return true;
            else return false;
        }
        if(s1.length()>s2.length())return false;
        return true;
    }
};
