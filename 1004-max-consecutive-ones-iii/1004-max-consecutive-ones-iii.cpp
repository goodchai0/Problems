class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int one,zero,l,r,ans;
        one=zero=l=r=ans=0;
        while(r<nums.size()){
            int x=nums[r];
            
            if(x==1)one++;
            if(x==0)zero++;
            if(zero>k){
                while(l<=r && nums[l]!=0)l++;
                l++;
                zero--;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};