class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size()<2)
            return arr.size();
        
        int ma=1;
        int start=0;
        int end=0;
        int len=arr.size();
        
        while(start+1<len){
            if(arr[start]==arr[start+1]){
                start++;
                continue;
            }
            end=start+1;
            while(end+1<len && isCurrentIndexTurbulent(arr,end)){
                end++;
            }
            ma=max(ma,end-start+1);
            start=end;
        }
        return ma;
    }
    
    bool isCurrentIndexTurbulent(vector<int>&arr,int k){
        return (arr[k]>arr[k-1] && arr[k]>arr[k+1]) || (arr[k]<arr[k-1] && arr[k]<arr[k+1]);
    }
};