class Solution {
public:
    int countOdds(int low, int high) {
        bool isFirst=(low&1)?true:false;
        bool isSecond=(high&1)?true:false;
        
        if(isFirst && isSecond){
            int ans=((high-low-1)/2);
            if(low==high)return ans+1;
            else return ans+2;
        }
        else{
            int ans= (high-low)/2;
            if(isFirst ||isSecond) return ans+1;
            return ans;
        } 
        
    }
};