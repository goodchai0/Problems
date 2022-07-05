class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longestStreak=0,currentStreak=0,currentNum;
        set<int>set;
        for(auto i:nums)
            set.insert(i);
        for(auto i:set)
        {
            //if greater number number is not there in the set,just run a while loop as we found a smallest number in the set and we can 
            //iterate and count the number greater than current num
            if(!set.count(i-1))
            {
                currentNum=i;
                currentStreak=1;
            }
            while(set.count(currentNum+1))
            {
                currentNum++;
                currentStreak++;
            }
            
            longestStreak=max(currentStreak,longestStreak);
        }
        return longestStreak;
    }
};