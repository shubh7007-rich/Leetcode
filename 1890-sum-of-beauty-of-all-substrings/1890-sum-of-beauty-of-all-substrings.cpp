class Solution {
public:
    int beautySum(string s) {
        unordered_map<char , int> freq;
        int n = s.length() , score = 0;


        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                int maxi = INT_MIN , mini = INT_MAX;
                freq[s[j]]++;
                for(auto [ch , f] : freq){
                    maxi = max(maxi , f);
                    mini = min(mini , f);
                }
                score += (maxi - mini);
            }
            freq.clear();
        }

        return score;
    }
};