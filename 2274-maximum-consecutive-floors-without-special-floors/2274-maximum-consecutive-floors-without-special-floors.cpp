class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int n=special.size();
        int floors=special[0]-bottom;
        for(int i=1;i<n;i++){
            floors=max(special[i]-special[i-1]-1,floors);
        }
        floors=max(top-special[n-1],floors);
        
        return floors;
    }
};