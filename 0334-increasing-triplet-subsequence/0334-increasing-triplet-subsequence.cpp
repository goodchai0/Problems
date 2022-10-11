class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int f=INT_MAX,s=INT_MAX;
        for(auto x:nums){
            if(x<f)
                f=x;
            else if(f<x && x<s)
                s=x;
            else if(x>s)
                return true;
        }
        return false;
    }
};

// class Solution {
// public:
//     bool increasingTriplet(vector<int>& nums) {
        
//         for(int i=0;i<nums.size()-2;i++){
//             int j=i+1;
//             int k=nums.size()-1;
//             while(j<k){
//                 if(nums[i]<nums[j]&& nums[j]<nums[k])
//                     return true;
                
//                 if(nums[i]<nums[k])
//                     j++;
//                 else 
//                     k--;
//             }
//         }
//         return false;
//     }
// };