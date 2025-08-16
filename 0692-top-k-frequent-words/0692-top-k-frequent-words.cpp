class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string , int> mp;

        for(string str : words){
            mp[str]++;
        }

        auto cmp = [](pair<int , string>& p1 , pair<int , string>& p2){
            if(p1.first == p2.first){
                return p1.second > p2.second;
            }
            return p1.first < p2.first;
        };

        priority_queue<pair<int , string> , vector<pair<int , string>> , decltype(cmp)> pq(cmp);

        for(auto [str , freq] : mp){
            pq.push({freq , str});
        }

        vector<string> ans;

        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};