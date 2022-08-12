class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int>mp1;
        unordered_map<int,int>firstSeen;
        int degree=0;
        int min_length=0;
        for(int i=0;i<nums.size();i++){
            if(!firstSeen.count(nums[i]))
                firstSeen[nums[i]]=i;
            mp1[nums[i]]++;
            if(mp1[nums[i]]>degree){
                degree=mp1[nums[i]];
                min_length=i-firstSeen[nums[i]]+1;
            }
            else if(mp1[nums[i]]==degree){
                min_length=min(min_length,i-firstSeen[nums[i]]+1);
            }
        }
        return min_length;
    }
};