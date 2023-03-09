class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=INT_MAX;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(canEatInTime(piles,mid,h))right=mid-1;
            else left=mid+1;
        }
        return left;
        
    }
    
    bool canEatInTime(vector<int>&piles,int mid,int h)
    {
        int hours=0;
        for(int pile:piles)
        {
            int div=pile/mid;
            hours+=div;
            if(pile%mid!=0) hours++;
        }
        return (hours<=h)?true:false;
    }
    
};