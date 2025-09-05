class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char , int> mp;
        int maxi = 0, i = 0;

        for(int j = 0 ; j < s.length() ; j++){
            mp[s[j]]++;

        
            while(i < j && (j-i+1 > mp.size())){
                mp[s[i]]--;

                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++;
            }

            if(j-i+1 == mp.size()){
                maxi = max(maxi , j-i+1);
            }
        }

        return maxi;
    }
};