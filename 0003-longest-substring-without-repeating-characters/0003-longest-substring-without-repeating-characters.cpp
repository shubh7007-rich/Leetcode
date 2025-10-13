class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char , int> freq;

        string str;
        int n = s.length() , ans = 0 , i = 0;

       
        for(int j = 0 ; j < n ; j++){
            freq[s[j]]++;

            while(i < j && freq.size() < j-i+1){
                freq[s[i]]--;

                if(freq[s[i]] == 0){
                    freq.erase(s[i]);
                }

                i++;
            }

            // if(freq.si)

            ans = max(ans , j-i+1);
        }

        return ans;

    }
};