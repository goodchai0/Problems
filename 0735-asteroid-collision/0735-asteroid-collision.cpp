class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        int n=asteroids.size();
        stack<int>s;
        
        
       for(int i=0; i<n; i++){
            if(asteroids[i] > 0 || s.empty()) s.push(asteroids[i]);
            else{
                while(!s.empty() && abs(asteroids[i]) > s.top() && s.top() > 0) s.pop();

                if(!s.empty() && abs(asteroids[i]) == s.top())s.pop();

                else if(s.empty() || s.top() < 0) s.push(asteroids[i]);
            }
        }
        
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};