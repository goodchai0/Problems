class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int ma=-1;
        if(nums.size()==1)
            return true;
        for(int i=0;i<nums.size()-2;i++)
        {
            ma=max(nums[i],ma);
            if(ma>nums[i+2])
            {
                return false;
            }
        }
        
        return true;
    }
};