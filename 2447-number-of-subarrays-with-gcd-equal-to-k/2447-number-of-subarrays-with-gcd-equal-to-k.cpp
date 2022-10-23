class Solution {
public:
    int gcd(int a,int b){
        if(b==0)
            return a;
        return gcd(b,a%b);
    }
    int subarrayGCD(vector<int>& nums, int k) {
        int ans=0;
        int _gcd;
        for(int i=0;i<nums.size();i++){
            _gcd=nums[i];
            for(int j=i;j<nums.size();j++){
                _gcd=gcd(_gcd,nums[j]);
                ans+=_gcd==k;
            }
        }
        return ans;
    }
};