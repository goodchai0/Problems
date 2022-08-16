#define mod 1000000007
class Solution {
public:
    
    long long help(int x,int y){
        if(y==1)return x;
        if(y==0)return 1;
        
        long long ans=1;
        
        if(y%2==0){
            ans=help(x,y/2);
            ans*=ans;
        }
        else{
            ans=help(x,y-1);
            ans*=x;
        }
        ans=ans%mod;
        return ans;
    }
    
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int s=0,e=nums.size()-1;
        
        while(s<=e){
            if(nums[s]+nums[e]<=target){
                ans+=(help(2,e-s));
                ans%=mod;
                s++;
            }
            else{
                e--;
            }
        }
        return ans;
        
    }
};