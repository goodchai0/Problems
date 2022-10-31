class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int mini=nums[0],maxi=nums[0];
        int res=1;
        for(auto x:nums){
            mini=min(x,mini);
            maxi=max(x,maxi);
            if(maxi-mini>k){
                res++;
                mini=x;
                maxi=x;
            }
        }
        return res;
    }
};