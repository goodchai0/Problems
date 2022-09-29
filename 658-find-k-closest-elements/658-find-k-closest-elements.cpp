class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {   
        int n=arr.size();
        int R=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int L=R-1;
        while(k--){
            if(R>=n || L>=0 && x-arr[L]<=arr[R]-x)L--;
            else R++;
        }
        return vector<int>(arr.begin()+L+1,arr.begin()+R);
    }
};