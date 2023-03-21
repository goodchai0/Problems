class Solution {
public:
long long zeroFilledSubarray(vector<int>& nums) {
    long long res = 0;
    for (int i = 0, j = 0; i < nums.size(); ++i) {
        if (nums[i] != 0)
            j = i + 1;
         res += i - j + 1;
    }
    return res;
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