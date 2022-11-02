class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sumFromBack=0,sumFromFront=0;
        for(auto x:nums)sumFromBack+=x;
        int n=nums.size();
        int res=0;
        for(int i=0;i<n-1;i++){
            int x=nums[i];
            sumFromFront+=x;
            sumFromBack-=x;
            if(sumFromFront>=sumFromBack)res++;
        }
        return res;
    }
    
};