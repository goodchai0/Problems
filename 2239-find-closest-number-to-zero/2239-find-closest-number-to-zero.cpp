class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ind=lower_bound(nums.begin(),nums.end(),0)-nums.begin();
       
        if(ind==0)
            return nums[ind];
        
        if(ind>=nums.size())
            return nums[nums.size()-1];
        
        if(abs(nums[ind])<=abs(nums[ind-1]))
        {
            return nums[ind];
        }
        else if(abs(nums[ind])>abs(nums[ind-1]))
            return nums[ind-1];
        return nums[ind];
    }
};

//test case casing problem=[-100000,-100000]