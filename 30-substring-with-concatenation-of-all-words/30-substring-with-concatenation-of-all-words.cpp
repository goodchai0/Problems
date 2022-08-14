class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        
        long long len=words[0].size();
        
        map<string,int>mp;
        
        for(auto x: words)
            mp[x]++;
        long long ssize=s.size(),wsize=words.size();
        // cout<<words.size()<<" "<<s.size()<<" "<<len<<" "<<(s.size()-(len*words.size()))<<" "<<ssize-len*wwords<<endl;
        
        for(long long i=0;i<=ssize-len*wsize;i++){
            
            cout<<"test 1"<<endl;
            map<string,int>copyMap;
            copyMap=mp;
            
            for(long long j=0;j<words.size();j++){
                string str=s.substr(i+j*len,len);
                // cout<<"test 2"<<endl;
                // // cout<<words.size()<<" "<<i+j*len+len<<endl;
                if(copyMap.count(str)){
                    int count=copyMap[str];
                    
                    if(count==1)copyMap.erase(str);
                    else copyMap[str]--;
                    if(copyMap.empty()){
                        ans.push_back(i);
                        break;
                    }
                } else{break;}
            }
        }
        return ans;
    }
};