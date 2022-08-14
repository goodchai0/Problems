class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank[0].size();
        int prevlaser=0;
        int ans=0;
        for(int i=0;i<bank.size();i++){
            int presentlaser=0;
            for(auto ch:bank[i]){
                if(ch=='1')
                    presentlaser++;
            }
            if(presentlaser>0){
                ans+=(presentlaser*prevlaser);
                prevlaser=presentlaser;
            }
        }
        return ans;
    }
};