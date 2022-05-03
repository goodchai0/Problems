class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>snums=nums;
        int start=INT_MAX,end=INT_MIN;
        bool flag=false;
        sort(snums.begin(),snums.end());
        for(int i=0;i<snums.size();i++)
        {
            if(snums[i]!=nums[i])
            {
                flag=true;
                 start=min(start,i);
                 end=max(end,i);
            }
           
        }
        if(flag==true)
        return end-start+1;
        else return 0;
    }
};