class Solution {
public:
    int jump(vector<int>& nums) {
        int far=0,cur=0,jumps=0;
        for(int i=0;i<nums.size()-1;i++){
            far=max(far,nums[i]+i);
            if(i==cur){
                cur=far;
                jumps++;
            }
        }
        return jumps;
    }
};