class Solution {
public:
        int largestRectangleArea(vector<int>& height) {
        int n=height.size();
        vector<int>s;
        vector<int>leftSmall(n,-1),rightSmall(n,n);
        
        for(auto i=0;i<n;i++){
            while(!s.empty() && height[i]<=height[s.back()])s.pop_back();
            leftSmall[i]=(s.empty())?-1:s.back();
            s.push_back(i);
            // cout<<leftSmall[i]<<" ";
        }
        
        s.clear();
        for(auto i=n-1;i>=0;i--){
            while(!s.empty() && height[i]<height[s.back()])s.pop_back();
            rightSmall[i]=(s.empty())?n:s.back();
            s.push_back(i);
            // cout<<rightSmall[i]<<" ";
        }
        
        int maxA=0;
        for(int i=0;i<n;i++){
            // cout<<rightSmall[i]-leftSmall[i]<<" ";
            maxA=max(maxA,height[i]*(rightSmall[i]-leftSmall[i]-1));
        }
        return maxA;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(m==0) return 0;
        int n=matrix[0].size(),result=0;
        vector<int>histogram(n,0);
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1')
                    histogram[j]+=1;
                else 
                    histogram[j]=0;
            }
            result=max(result,largestRectangleArea(histogram));
            //cout<<result<<" ";
        }
        return result;
    }
};