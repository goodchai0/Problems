class MyCalendar {
public:
    set<pair<int,int>>s;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it=s.upper_bound({start,end});
        if(it->first>start&&it->second<end)
        {
             return false;
        }
           
        s.insert({end,start});
            return true;
    }
};



// class MyCalendar {
// public:
//         vector<pair<int,int>>m;
//     MyCalendar() {
        
//     }
    
//     bool book(int start, int end) {
//         for(auto it:m){
//             if(it.first<end && start<it.second)
//                 return false;
//         }
//         m.push_back({start,end});
//         return true;
//     }
// };

// /**
//  * Your MyCalendar object will be instantiated and called as such:
//  * MyCalendar* obj = new MyCalendar();
//  * bool param_1 = obj->book(start,end);
//  */