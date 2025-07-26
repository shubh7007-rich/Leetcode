class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0 , maxi = 0;
        unordered_map<char , int> mp;
        for(int j = 0 ; j < s.length() ; j++){
            mp[s[j]]++;

            while(mp.size() < j-i+1){
                mp[s[i]]--;

                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++;
            }
            maxi = max(maxi , j-i+1);
        }   
        return maxi;
    }
};