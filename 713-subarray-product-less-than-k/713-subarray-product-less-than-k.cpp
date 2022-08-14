class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        long long prod=1,ans=0,j=0;
        if(k==0)
            return 0;
        for(int i=0;i<nums.size();i++){
            prod*=nums[i];
            while(prod>=k && j<=i){
                prod/=nums[j];
                j++;
            }
            ans+=(i-j+1);
            
        }
        return ans;
    }
};