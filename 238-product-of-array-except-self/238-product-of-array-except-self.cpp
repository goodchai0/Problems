//we can do this question by using two array which will store left product and right product and then by multiplying the same indexes .
//but we need to do it in O(1) space complexity.

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>output(nums.size(),1);
        //output[0]=1;
        for(int i=1;i<nums.size();i++)
        {
            output[i]=output[i-1]*nums[i-1];
        }
        int r=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            output[i]=r*output[i];
            r=r*nums[i];
        }
        return output;
    }
};

