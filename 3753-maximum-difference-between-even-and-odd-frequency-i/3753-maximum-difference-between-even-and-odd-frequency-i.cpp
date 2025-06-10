class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26 , 0);

        for(char ch : s){
            freq[ch-'a']++;
        }
        int even = INT_MAX , odd = INT_MIN;

        for(int i = 0 ; i < 26 ; i++){
            if(freq[i]&1){
                odd = max(odd , freq[i]);
            }else if(freq[i] > 0 && !(freq[i]&1)){
                even = min(even , freq[i]);
            }
        }

        return odd - even;
    }
};