class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto x:stones)
        {
            pq.push(x);
        }
        while(pq.size()!=1)
        {
            int p1=pq.top();
            pq.pop();
            int p2=pq.top();
            pq.pop();
            p1-=p2;
            pq.push(p1);
        }
        return pq.top();
    }
};