class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        
        int b=INT_MAX,count=0;
        for(auto x:nums){
            b&=x;
        }
        if(b>0)return 1;
        b=INT_MAX;
        for(auto x:nums){
            b&=x;
            if(b==0){
                count++;
                b=INT_MAX;
            }
        }
        return count;
    }
};