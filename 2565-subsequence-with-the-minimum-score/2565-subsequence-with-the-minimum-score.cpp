class Solution {
public:
    int minimumScore(string s, string t) {
        int n=s.size();
        int m=t.size();
        
        vector<int>pref(m,n);
        vector<int>suff(m,-1);
        
        for(int i=0,j=0;i<s.size() && j<t.size();i++){
            if(s[i]==t[j])
                pref[j++]=i;
        }
        
        for(int i=s.size()-1,j=t.size()-1 ;i>=0 && j>=0;i--){
            if(s[i]==t[j])
                suff[j--]=i;
        }
        
        if(pref.back()!=n)
            return 0;
        
        int tot=t.size();
        
        int i=0,j=0;
        
        // if(pref[0]==n){
        //     if(suff[m-1]==-1)
        //         tot=min(tot,m);
        //     else{
        //         j=m-1;
        //         while(suff[j]!=-1)
        //             j--;
        //         tot=min(m-j,tot);
        //     }
        // }
        
        i=0,j=0;
        
        for(i=0;i<m;i++){
            if(pref[i]==n) 
                break;
            while(j<m && suff[j]<=pref[i])
                j++;
            tot=min(tot,j-i-1);
        }
        
            
        // cout<<i<<" "<<j<<" "<<tot<<" "<<suff[j]<<endl;
        ////////////////////////////////////////////
        for(int i=0;i<m;i++){
            cout<<pref[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<m;i++){
            cout<<suff[i]<<" ";
        }
        
        //////////////////////////////////////////////
        for(int i=m-1; i>=0; i--)
        {
            if(suff[i]!=-1)
                tot=min(tot, i);
        }

        return tot;
        // return 0;
        
    }
};