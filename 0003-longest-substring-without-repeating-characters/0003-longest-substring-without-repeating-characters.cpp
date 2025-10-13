class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // unordered_map<char , int> mp;
        string str;
        int n = s.length() , ans = 0;

        for(int i = 0 ; i < n ; i++){
            // vector<int> freq(26 , 0);
            unordered_map<char , int> freq;

            for(int j = i ; j < n ; j++){
                freq[s[j]]++;
                bool flag = true;
                
                if(freq.size() < j-i+1) flag = false;

                if(!flag) break;

                ans = max(ans , j-i+1);
            }
        }

        return ans;


    }
};