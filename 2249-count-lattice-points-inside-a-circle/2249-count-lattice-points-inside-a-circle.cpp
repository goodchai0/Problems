class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int,int>>s;
        for(auto x:circles){
            int a=x[0],b=x[1],r=x[2];
            for(int i=-a;i<=a;i++){
                for(int j=-b;j<=b;j++){
                    if(i*i+j*j<=r*r){
                        s.insert({a+i,b+j});
                    }
                }
            }
        }
        return s.size();
        
    }
};