class MyHashMap {
    
    int keyvalues[10000001]={0};
public:
    MyHashMap() {
    
    }
    
    void put(int key, int value) {
        if(value==0)
            keyvalues[key]=-1;
        else
        {
            keyvalues[key]=value;
        }
    }
    
    int get(int key) {
        if(keyvalues[key]==-1)
            return 0;
        
        else if(keyvalues[key]==0)
            return -1;
        else return keyvalues[key];
    }
    
    void remove(int key) {
        keyvalues[key]=0;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */