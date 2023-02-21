class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0,h=nums.size()-1;
        int ans,mid;
        
        while(l<=h){
            mid=(l+h)/2;
            ans=nums[mid];
            if(mid>0 && mid<nums.size()-1 && nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
                return ans;
            
            if(mid%2==1 && mid>0 && nums[mid]==nums[mid-1])
                l=mid+1;
            else if(mid%2==0 && mid<nums.size()-1 && nums[mid+1]==nums[mid])
                l=mid+2;
            else{
                h=mid-1;
            }
        }
        return ans;
    }
};