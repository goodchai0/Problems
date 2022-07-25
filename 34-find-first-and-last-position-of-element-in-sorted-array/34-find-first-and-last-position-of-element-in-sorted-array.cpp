class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int ans=-1,ans1=-1;
        vector<int>v;
        int l=0,hi=nums.size()-1;
        while(l<=hi)
        {
            int mid=l-(l-hi)/2;
            if(nums[mid]>target)
            {
                hi=mid-1;
            }
            else if(nums[mid]<target)
            {
                l=mid+1;
            }
            else{
                ans=mid;
                hi=mid-1;
            }
        }
        
        l=0,hi=nums.size()-1;
        while(l<=hi)
        {
            int mid=l-(l-hi)/2;
            if(nums[mid]>target)
            {
                hi=mid-1;
            }
            else if(nums[mid]<target)
            {
                l=mid+1;
            }
            else{
                ans1=mid;
                l=mid+1;
            }
        }
        
        
        if(ans!=-1)
            v.push_back(ans);
        else v.push_back(-1);
        
        if(ans1!=-1)
            v.push_back(ans1);
        else v.push_back(-1);
        
        
        return v;
        
    }
};