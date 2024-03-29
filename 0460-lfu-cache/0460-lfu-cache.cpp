class LFUCache {
private:
    int cap;
    int size;
    unordered_map<int,list<vector<int>>::iterator>mp;
    map<int,list<vector<int>>>freq;
    
public:
    LFUCache(int capacity) {
        cap=capacity;
        size=0;
    }
    
    void makeMostFrequentlyUsed(int key){
        auto &vec = *(mp[key]);
        int value = vec[1];
        int f = vec[2];
        
        freq[f].erase(mp[key]);
        
        if(freq[f].empty())
            freq.erase(f);
        
        f++;
        freq[f].push_front(vector<int>({key,value,f}));
        
        mp[key]=freq[f].begin();
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        
        auto &v=(*mp[key]);
        int value=v[1];
        
        makeMostFrequentlyUsed(key);
        
        return value;
    }
    
    void put(int key, int value) {
        if(cap==0)
            return;
        
        if(mp.find(key)!=mp.end()){
            auto &vec=(*mp[key]);
            vec[1]=value;
            makeMostFrequentlyUsed(key);
        }
        else if(size<cap){
            size++;
            freq[1].push_front(vector<int>({key,value,1}));
            mp[key]=freq[1].begin();
        }
        else{
            ///removing
            
            auto &remove_list=freq.begin()->second;
            int key_delete=remove_list.back()[0];
            
            remove_list.pop_back();
            
            if(remove_list.empty())
                freq.erase(freq.begin()->first);
            
            freq[1].push_front(vector<int>({key,value,1}));
            
            mp.erase(key_delete);
            mp[key]=freq[1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */