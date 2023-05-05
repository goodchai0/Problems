class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.length();
        if(n<k)return 0;
        vector<int>v(n+1,0);
        for(int i=0;i<n;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                v[i+1]+=1;
            }
            v[i+1]+=v[i];
            // cout<<v[1+i]<<" ";
        }
        int ma=INT_MIN;
        for(int i=0;i<=n-k;i++){

                ma=max(ma,v[i+k]-v[i]);
                cout<<ma<<" ";
            
        }
        return ma;
    }
};