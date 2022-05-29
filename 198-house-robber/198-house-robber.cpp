class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
        
        for(int i=1;i<n;i++)
        {
            int take=nums[i];
            if(i>1)
                take+=prev2;
            int notTake=prev;
            
            int curr=max(take,notTake);
          
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};



// class Solution {
// public:
//     vector<int> dp;
//     int f(vector<int>nums,int ind)
//     {
//         if(ind==0)return nums[ind];
//         if(ind<0) return 0;
//         if(dp[ind]!=-1)
//             return dp[ind];
//         int pick=nums[ind]+f(nums,ind-2);
//         int notpick=f(nums,ind-1);
        
//         return dp[ind]=max(pick,notpick);
//     }
//     int rob(vector<int>& nums) {
//         int index=nums.size()-1;
//         dp.resize(index+1,-1);
//         return f(nums,index);
        
//     }
// };