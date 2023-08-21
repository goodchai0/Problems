class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int>mp;
        
        for(auto x:nums){
            mp[((x%value)+value)%value]++;
        }
        
        int stop=0;
        for(int i=0;i<value;i++){
            if(mp[i]<mp[stop]){
                stop=i;
            }
        }
        return value*mp[stop]+stop;
    }
};