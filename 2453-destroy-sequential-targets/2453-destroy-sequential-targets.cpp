class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int,int>mp;
        int maxc=0;
        for(auto x:nums){
            maxc=max(++mp[x%space],maxc);
        }
        int res=999999999;
        for(int x:nums){
            if(mp[x%space]==maxc)
                res=min(res,x);
        }
        return res;
    }
};