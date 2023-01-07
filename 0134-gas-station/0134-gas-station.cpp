class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int tank=0,n=gas.size(),j=0;
        for(int i=0;i<n;i+=j){
            tank=0;
            for( j=1;j<=n;j++){
                int k=(i+j-1)%n;
                tank+=gas[k]-cost[k];
                if(tank<0)
                    break;
            }
            if(j>n)
                return i;
        }
        return -1;
    }
};