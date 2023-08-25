class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto x:nums)mp[x]++;
        for(int i=0;i<32;i++){
            if(!mp[1<<i])return 1<<i;
        }
        return 0;
    }
};