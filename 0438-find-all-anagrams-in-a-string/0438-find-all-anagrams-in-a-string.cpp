class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>map1(26),map2(26);
        for(char i:p){
            map1[i-'a']++;
        }
        vector<int>ans;
        for(int i=0;i<s.size();i++){
            map2[s[i]-'a']++;
            if(i>=p.size()-1){
                if(map1==map2)ans.push_back(i+1-p.size());
            
                map2[s[i+1-p.size()]-'a']--;
            }
        }
        return ans;
    }
};