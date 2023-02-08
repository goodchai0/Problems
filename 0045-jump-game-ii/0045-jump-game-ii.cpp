// class Solution {
// public:
//     int helper(int index,vector<int>& nums,int steps,vector<int>&dp){
//         if(index==nums.size()-1){
//             return steps;
//         }
        
//         if(dp[index]!=-1)
//             return dp[index];
        
//         else if(index>=nums.size()){
//             return INT_MAX;
//         }
//         int ans=INT_MAX;
//         for(int i=1;i<=nums[index];i++){
//             if(i+index<=nums.size()){
//                 int res=helper(index+i,nums,steps+1,dp);
//                 ans=min(res,ans);
//                 if(res!=INT_MAX)
//                     dp[index]=ans;
//             }
//             else break;
           
//         }
//         return dp[index]=ans;
//     }
//     int jump(vector<int>& nums) {
//         vector<int>dp(nums.size()+1,-1);

//         int ans1=helper(0,nums,0,dp);
//         return ans1;
//     }
// };
class Solution {
   
    int solve(int ind,vector<int>&nums,vector<int>&dp)
    {
        if(ind>=nums.size()-1)
            return 0;    
        
        if(dp[ind]!=-1)
            return dp[ind];   
        
        int m=INT_MAX;   
        for(int i=1;i<=nums[ind];i++)
        {
            int a=solve(ind+i,nums,dp);
            if(a!=INT_MAX)    
                m=min(a+1,m);
        }
        return dp[ind]=m;     
    }
public:
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
      return solve(0,nums,dp);     
        
    }
};