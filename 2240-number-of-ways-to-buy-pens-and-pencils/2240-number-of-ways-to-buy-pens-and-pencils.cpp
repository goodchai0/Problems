class Solution {
public:
long long waysToBuyPensPencils(int total, int pen, int pencil) {
        
        long long ans=0;
        for(int i=0;i<=total/pen;i++)  //i can buy 0 pen 1 pen 2 pen 3 and so on
        {
            int remain=total-pen*i; //remaining amount by which i can buy pencils
            ans+=remain/pencil +1;  //i can buy 0,1,2,3, ... remain/pencil tak 
        }
        return ans;
    }
};