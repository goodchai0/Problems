class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int ar) {
        for(int i=0;i<capacity.size();i++){
            capacity[i]-=rocks[i];
        }
        
        sort(capacity.begin(),capacity.end());
        int res=0;
        for(auto x:capacity){
            cout<<x<<" "<<ar<<endl;
            if(x<=ar){
                res++;
                ar-=x;
            }
            else break;
        }
        return res;
    }
};