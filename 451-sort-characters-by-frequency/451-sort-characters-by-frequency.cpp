class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>m1;
        multimap<int,char,greater<int>>m2;
        string st="";
        int i,j=0;
        for(auto x:s)
            m1[x]++;
        
        for(auto it=m1.begin();it!=m1.end();it++)
            m2.insert({it->second,it->first});
        for(auto it=m2.begin();it!=m2.end();it++){
            for(auto i=0;i<it->first;i++){
                st+=it->second;
               
            }
        }
        return st;
    }
};