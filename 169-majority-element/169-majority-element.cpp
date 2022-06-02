class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int count=0;
        int majority=0;
        for(auto x:nums)
        {
            if(count==0)
            {
                majority=x;
                count++;
            }
            else
            {
                if(x==majority)
                    count+=1;
                else count-=1;
            }
        }
        
        return majority;
        
    }
};