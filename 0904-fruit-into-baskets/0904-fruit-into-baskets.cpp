class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0,j=0;
        int res=0;
        unordered_map<int,int>mp;
        while(j<fruits.size()){
            mp[fruits[j]]++;
            if(mp.size()<=2)res=max(res,j-i+1);
            else{
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0)mp.erase(fruits[i]);
                i++;
            }
            j++;
        }
        return res;
    }
};