class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                nums[j++]=nums[i];
            }
        }
        for(;j<nums.size();j++)
            nums[j]=0;
    }
};


//class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         vector<int>ans;
//         int count=0;
//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums[i]!=0)
//                 ans.push_back(nums[i]);
//             else count++;
//         }
//         while(count--)
//         {
//             ans.push_back(0);
//         }
//         nums=ans;

//     }
// };