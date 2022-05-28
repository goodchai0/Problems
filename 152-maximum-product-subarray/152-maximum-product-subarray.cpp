class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int maxp=INT_MIN,prod=1;
        for(int i=0;i<arr.size();i++)
        {
            prod*=arr[i];
            maxp=max(maxp,prod);
            if(prod==0){
                prod=1;
            }
        }
        prod=1;
        for(int i=arr.size()-1;i>=0;i--)
        {
            prod*=arr[i];
            maxp=max(maxp,prod);
            if(prod==0)
                prod=1;
        }
        
        return maxp;
    }
};