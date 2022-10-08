class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min_diff=INT_MAX;
        int res=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            int k=nums.size()-1;
            
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                
                if(abs(target-sum)<min_diff){
                    min_diff=min(abs(target-sum),min_diff);
                    res=sum;
                }
                if(sum<target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return res;
    }
};