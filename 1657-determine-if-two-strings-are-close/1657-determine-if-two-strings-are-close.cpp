class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>count1(26,0),count2(26,0);
        set<int>s,s1;
        
        for(auto x:word1){
            count1[x-'a']++;
            s.insert(x);
        }
        for(auto x:word2){
            count2[x-'a']++;
            s1.insert(x);
        }
        sort(count1.begin(),count1.end());
        sort(count2.begin(),count2.end());
        return s1==s && count1==count2;
    }
};