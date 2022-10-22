class FoodRatings {
public:
    unordered_map<string,map<int,set<string>>>crf;
    unordered_map<string,pair<int,string>>fcr;
    FoodRatings(vector<string>& food, vector<string>& cuisines, vector<int>& rating) {
        int n=food.size();
        for(int i=0;i<n;i++){
            crf[cuisines[i]][rating[i]].insert(food[i]);
            fcr[food[i]]=make_pair(rating[i],cuisines[i]);
        }
    }
    
    void changeRating(string food, int newRating) {
        auto [prevRating,cuisine]=fcr[food];
        crf[cuisine][prevRating].erase(food);
        if(crf[cuisine][prevRating].empty()){
            crf[cuisine].erase(prevRating);
        }
        
        crf[cuisine][newRating].insert(food);
        fcr[food].first=newRating;
    }
    
    string highestRated(string cuisine) {
        auto foodSet=crf[cuisine].rbegin()->second;
        return *foodSet.begin();
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */