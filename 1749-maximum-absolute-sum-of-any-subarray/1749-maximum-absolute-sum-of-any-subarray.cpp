class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int curr=0,ma=INT_MIN;
        for(int i=0;i<n;i++){
            curr+=nums[i];
            ma=max(curr,ma);
            if(curr<0)
                curr=0;
        }
        cout<<ma;
        int mi=INT_MAX;
        curr=0;
        for(int i=0;i<n;i++){
            curr+=nums[i];
            mi=min(curr,mi);
            if(curr>0)
                curr=0;
        }   
        return max(abs(ma),abs(mi));
    }
};