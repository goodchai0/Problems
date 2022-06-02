class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        for(auto i:nums)
            sum+=i;
        int curr=0;
        int ans=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(sum-curr-nums[i]==curr)
            {
                ans=i;break;
            }
            else 
                curr+=nums[i];
            
            
        }
        return ans;
    }
};







// solve i tried and failed.
//class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         int i=0;
//         int j=nums.size()-1;
//         int sum1=nums[0];
//         int sum2=nums[j];
//         int ans=-1;
//         while(i<j)
//         {
//             if(sum1<sum2)
//             {
//                 i++;
//                 sum1+=nums[i];
//             }
//             else
//                 if(sum1>sum2)
//                 {
//                     j--;
//                     sum2+=nums[j];
//                 }
//             else{
//                 ans=i+1;
//                 break;
//             }
//         }
//         if((i+j)==nums.size()-1)
//             return -1;
//         else return ans;
//     }
// };