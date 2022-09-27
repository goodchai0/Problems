class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();
        vector<int>left(n,0),right(n,0);
        right[0]=dominoes[0]=='R'?1:0;
        left[n-1]=dominoes[n-1]=='L'?1:0;
        for(int i=1;i<n;i++){
            if(dominoes[i]=='R'){
                right[i]=1;
            }
            else if(dominoes[i]=='.'){
                right[i]+=(right[i-1]>0)?right[i-1]+1:0;
            }
            else{
                right[i]=0;
            }
        }
        
        
        for(int i=n-2;i>=0;i--){
            if(dominoes[i]=='L'){
                left[i]=1;
            }
            else if(dominoes[i]=='.'){
                left[i]+=(left[i+1]>0)?left[i+1]+1:0;
            }
            else{
                left[i]=0;
            }
        }
        
        string res="";
        
        for(int i=0;i<n;i++){
            if(right[i]==left[i])res+='.';
            else if(!right[i])res+='L';
            else if(!left[i])res+='R';
            else if(left[i]>right[i])res+='R';
            else if(left[i]<right[i])res+='L';
        }
        
        return res;
        
    }
};