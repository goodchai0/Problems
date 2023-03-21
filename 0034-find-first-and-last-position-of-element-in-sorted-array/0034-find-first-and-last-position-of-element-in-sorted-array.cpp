class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int ans=-1,ans1=-1;
        int l=0,hi=nums.size()-1;
        while(l<=hi)
        {
            int mid=l-(l-hi)/2;
            if(nums[mid]==target){
                ans=mid;
                hi=mid-1;
            }
            else if(nums[mid]>target)
            {
                hi=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        
        l=0;hi=nums.size()-1;
        while(l<=hi)
        {
            int mid=l-(l-hi)/2;
            if(nums[mid]==target){
                ans1=mid;
                l=mid+1;
            }
            else if(nums[mid]>target)
            {
                hi=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        
        return {ans,ans1};
        
    }
};