class Solution {
public:
    string clearStars(string s) {
        using pii = pair<char ,int>;

        auto cmp = [](pii a , pii b){
            if(a.first == b.first){
                return a.second < b.second;
            }

            return a.first > b.first;
        };

        priority_queue<pii , vector<pii> , decltype(cmp)> pq;

        vector<int> marked(s.length() , 0);

        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '*'){
                marked[i] = 1;

                if(!pq.empty()){
                    auto p = pq.top();
                    marked[p.second] = 1;
                    pq.pop();

                }
            }else{
                pq.push({s[i] , i});
            }
        }

        string ans = "";

        for(int i = 0 ; i < s.length() ; i++){
            if(marked[i] == 0){
                ans += s[i];
            }
        }

        return ans;
    }
};