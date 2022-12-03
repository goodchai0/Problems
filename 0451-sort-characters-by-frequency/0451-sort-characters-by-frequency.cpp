class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>m1;
        priority_queue<pair<int,char>>maxHeap;
        string st="";
        int i,j=0;
        for(auto x:s)
            m1[x]++;
        
        for(auto x:m1)
            maxHeap.push({x.second,x.first});
        while(!maxHeap.empty()){
            int n=maxHeap.top().first;
            while(n--)
                st+=maxHeap.top().second;
            maxHeap.pop();
        }
        
        return st;
    }
};
