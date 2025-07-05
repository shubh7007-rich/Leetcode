class Solution {
public:
    int characterReplacement(string s, int k) {
        // length of the window - MaxFreq of character <= k ---> valid window

        vector<int> freq(26 , 0);
        int i = 0 , ans = 1;
        for(int j  = 0 ; j < s.length() ; j++){
            freq[s[j] - 'A']++;
            int maxi = 0;
            for(int & f : freq) maxi = max(maxi , f);

            int lenOfWindow = j-i+1;

            while(lenOfWindow - maxi > k){
                freq[s[i]-'A']--;
                i++;

                for(int & f : freq) maxi = max(maxi , f);

                lenOfWindow = j-i+1;
            }

            if(lenOfWindow - maxi <= k) ans = max(ans , j-i+1);

        }
        return ans;
    }
};