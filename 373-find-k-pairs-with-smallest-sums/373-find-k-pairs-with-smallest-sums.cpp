class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        for(int i=0;i<nums1.size() && k!=0;i++)
        {
                int sum=nums1[i]+nums2[0];
                pq.push({sum,{i,0}});

        }
        vector<vector<int>>ans;
        while(pq.size()!=NULL &&k-- )
        {
            auto p=pq.top();
            pq.pop();
            
            int i=p.second.first,j=p.second.second;
            
            ans.push_back({nums1[i],nums2[j]});
            
            if(j<nums2.size()-1)
            {
                pq.push({nums1[i]+nums2[j+1],{i,j+1}});
            }
        }
        
         return ans;
    }
};

//https://www.youtube.com/watch?v=WhIcVlkZ19s&ab_channel=KnowledgeCenter
//why priority queue has all this arguement, see in above video.