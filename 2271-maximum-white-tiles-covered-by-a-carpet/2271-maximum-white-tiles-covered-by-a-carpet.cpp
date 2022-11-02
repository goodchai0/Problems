class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        
        sort(tiles.begin(),tiles.end());
        int n=tiles.size();
        
        int prefix[n+1],et[n];
        
        prefix[0]=0;
        
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+(tiles[i][1]-tiles[i][0]+1);
            et[i]=tiles[i][1];
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            int start=tiles[i][0];
            int end=start+carpetLen-1;
            
            int idx=upper_bound(et,et+n,end)-et;
            
            int tsum=prefix[idx]-prefix[i];
            
            if(idx<n && end>=tiles[idx][0])
                tsum+=end-tiles[idx][0]+1;
            
            ans=max(ans,tsum);
        }
        
        return ans;
    }
};