class FoodRatings {
public:
    unordered_map<string , string> cusineBata; // food - cuisine
    unordered_map<string , set<pair<int , string>>> highFood;  // cuisine --> {rating , food}
    unordered_map<string , int> old_rating;  // food - rating


    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0 ; i < n ; i++){
            cusineBata[foods[i]] = cuisines[i];
            old_rating[foods[i]] = -ratings[i];
            highFood[cuisines[i]].insert({-ratings[i] , foods[i]});
        }
    }

    
    void changeRating(string food, int newRating) {
        int old = old_rating[food];
        string cui = cusineBata[food];

        highFood[cui].erase({old , food});
        highFood[cui].insert({-newRating , food});

        old_rating[food] = -newRating;
    }
    
    string highestRated(string cuisine) {
        auto p = *highFood[cuisine].begin();
        return p.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */