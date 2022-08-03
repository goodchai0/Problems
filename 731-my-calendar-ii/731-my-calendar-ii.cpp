class MyCalendarTwo {
public:
    vector<pair<int,int>>events;
    vector<pair<int,int>>doublebooking;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(auto p:doublebooking)
        {
            if(p.second>start && p.first<end)
            {
                return false;
            }
        }
        
        for(auto p:events)
        {
            if(p.second>start && p.first<end)
            {
                doublebooking.push_back({max(start,p.first),min(end,p.second)});
            }
        }
        events.push_back({start,end});
        return true;
    }
    
    
};

// class MyCalendarTwo {
// public:
//     map<int,int>m;
//     MyCalendarTwo() {
        
//     }
    
//     bool book(int start, int end) {
//         m[start]++;
//         m[end]--;
//         int sum=0;
//         for(auto it:m){
//             sum+=it.second;
//             if(sum>=3)
//             {
//                 m[start]--;
//                 m[end]++;
//                 return false;
//             }
//         }
//         return true;
//     }
// };

// /**
//  * Your MyCalendarTwo object will be instantiated and called as such:
//  * MyCalendarTwo* obj = new MyCalendarTwo();
//  * bool param_1 = obj->book(start,end);
//  */