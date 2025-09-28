class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string , int> freq;

        for(string str : words){
            freq[str]++;
        }

        vector<pair<int , string>> vec;
        vector<string> ans;

        for(auto [str, f] : freq){
            vec.push_back({-f , str});
        }
        int cnt = 0;
        sort(vec.begin() , vec.end());

        for(auto p : vec){
            ans.push_back(p.second);
            cnt++;
            if(cnt == k) break;
        }

        return ans;
    }
};