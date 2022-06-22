class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i;j<nums.size();j++)
            {
                if(nums[i]<nums[j])
                    swap(nums[i],nums[j]);
            }
        }
        return nums[k-1];
    }
};