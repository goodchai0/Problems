class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[26]={0};
        
        for(auto ch:magazine)
            count[ch-'a']++;
        
        for(auto ch:ransomNote)
            if(count[ch-'a'])
                count[ch-'a']--;
            else return false;
        
        return true;
    }
};