class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int l,r,ans,odd,cnt;
        l=r=ans=odd=cnt=0;
        
        while(r<n){
            if(nums[r]&1){
                odd++;
                ans=0;
            }
            while(odd==k){
                ans++;
                odd-=nums[l++]&1;
            }
            cnt+=ans;
            r++;
        }
        return cnt;
    }
};