class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0)return 0;
        
        int maxleft[height.size()];
        int maxright[height.size()];
        
        maxleft[0]=height[0];
        for(int i=1;i<height.size();i++){
            maxleft[i]=max(maxleft[i-1],height[i-1]);
        }
        maxright[height.size()-1]=0;
        for(int i=height.size()-2;i>=0;i--){
            maxright[i]=max(maxright[i+1],height[i+1]);
        }
        int res=0;
        for(int i=0;i<height.size();i++){
            int waterAbove=min(maxleft[i],maxright[i])-height[i];
            if(waterAbove>0)
                res+=waterAbove;
        }
        return res;
    }
};