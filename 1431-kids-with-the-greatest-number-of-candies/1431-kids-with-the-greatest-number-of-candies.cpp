class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int n=candies.size();
        vector<int>v(n);
        vector<bool>b(n);
        
        for(int i=0;i<candies.size();i++)
        {
            v[i]=candies[i];
        }
        sort(v.begin(),v.end(),greater<int>());
        int ma=v[0];
        
        for(int i=0;i<candies.size();i++)
        {
            if((candies[i]+extraCandies)>=ma)
            {
                b[i]=true;
            }
            else
                b[i]=false;
        }
        return b;
    }
};