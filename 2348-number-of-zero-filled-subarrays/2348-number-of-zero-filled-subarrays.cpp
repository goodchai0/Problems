class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long j=0,ans=0;
        for(long long i=0;i<nums.size();i++){
            if(nums[i]!=0){
                j=i+1;
            }
            ans+=i-j+1;
        }
        return ans;
    }
};

// class Solution {
// public:
//     long long zeroFilledSubarray(vector<int>& nums) {
//         long long ans=0;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==0){
//                 long long j=0;
//                 while(i<nums.size() && nums[i]==0){
//                     j++;
//                     i++;
//                 }
//                 ans+=(j*(j+1))/2;
//             }
//         }
//         return ans;
//     }
// };