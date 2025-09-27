class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char , int> freq;

        for(char ch : s) freq[ch]++;

        string str = "";

        vector<pair<int , char>> vec;

        for(auto [ch , f] : freq){
            vec.push_back({-f , ch});
        }

        sort(vec.begin() , vec.end());

        for(auto p : vec){
            char ch = p.second;
            int t = abs(p.first);

            while(t--){
                str.push_back(ch);
            }
        }

        return str;
    }
};