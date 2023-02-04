class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>map1(26),map2(26);
        for(char i:s1){
            map1[i-'a']++;
        }
        for(int i=0;i<s2.size();i++){
            map2[s2[i]-'a']++;
            if(i>=s1.size()-1){
                if(map1==map2)return true;
            
                map2[s2[i+1-s1.size()]-'a']--;
            }
        }
        return false;
    }
};