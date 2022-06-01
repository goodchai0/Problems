class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0;
        int j=prices.size();
        int buy=INT_MAX,pro=INT_MIN;
        for(int i=0;i<j;i++)
        {
        
                buy=min(prices[i],buy);
                pro=max(pro,prices[i]-buy);
              
        }
        if(pro<0)
             return 0;
        else return pro;
    }
};