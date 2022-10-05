class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char,int>mp;
        
        for(auto x:word){
            mp[x]++;
        }
        
        unordered_map<int,int>freq;
        
        for(auto x:mp)
            freq[x.second]++;
        
        for(auto x:mp)
            cout<<freq[x.second]<<" ";
        
        if(freq.size()>2)
            return false;
        
        cout<<freq.size();
        
        if(freq.size()==1){
            
            auto it=freq.begin();
            
            if(it->second==1 || it->first==1) // if all the number has freq 1 then its possile to remove 1 of them or if only one element is there 
                return true;
            
            return false;
        }
        
        auto it=freq.begin();
        auto it2=it++;
        
        if((it->second==1 && it->first==1) || (it2->second==1&&  it2->first==1))
            return true;
        if(((it->first==1 && it2->first==2) || (it2->first==1 && it->first==2)) && (it->second==1 || it2->second==1))
        return true;
        
        if(((abs(it->first-it2->first)==1)))
       {
            int mini=min(it->first,it2->first);
            if(mini==it2->first && it->second==1)
                return true;
            else if(mini==it->first && it2->second==1)
                return true;
       }
        
        return false;
        
    }
};