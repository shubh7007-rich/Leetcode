struct cmp {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    }
};

class MovieRentingSystem {
public:
    // movie -> { {shop, price} ... } for unrented
    map<int, set<pair<int,int>, cmp>> unrentedMovies;
    // movie -> { {shop, price} ... } for rented
    map<int, set<pair<int,int>, cmp>> rentedMovies;
    // for report -> {price, {shop, movie}}
    set<pair<int, pair<int,int>>> forReport;

    // quick lookup: (shop, movie) -> price
    map<pair<int,int>, int> priceLookup;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &vec : entries) {
            int shop = vec[0], movie = vec[1], price = vec[2];
            unrentedMovies[movie].insert({shop, price});
            priceLookup[{shop, movie}] = price;
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ans;
        int k = 0;
        for (auto &p : unrentedMovies[movie]) {
            ans.push_back(p.first);
            if (++k == 5) break;
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        int price = priceLookup[{shop, movie}];
        unrentedMovies[movie].erase({shop, price});
        rentedMovies[movie].insert({shop, price});
        forReport.insert({price, {shop, movie}});
    }
    
    void drop(int shop, int movie) {
        int price = priceLookup[{shop, movie}];
        rentedMovies[movie].erase({shop, price});
        unrentedMovies[movie].insert({shop, price});
        forReport.erase({price, {shop, movie}});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        int k = 0;
        for (auto &p : forReport) {
            int shop = p.second.first, movie = p.second.second;
            res.push_back({shop, movie});
            if (++k == 5) break;
        }
        return res;
    }
};
