class Solution {
public:
    int characterReplacement(string s, int k) {
        /*
            AABABBA  , k = 1

            length of the window - most frequent character of the substring or window

        */
        int n = s.length() , ans = 0;

        // for(int i = 0 ; i < n; i++){
        //     vector<int> freq(26 , 0);
        //     int mostFreq = 0;

        //     for(int j = i ; j < n ; j++){

        //         freq[s[j]-'A']++;

        //         for(int e = 0 ; e < 26 ; e++){
        //             if(freq[e] > mostFreq){
        //                 mostFreq = freq[e];
        //             }
        //         }

        //         if(j-i+1 - mostFreq > k) break;

        //         ans = max(ans , j-i+1);
        //     }
        // }

        // O(n*n*26) --> O(26 * n^2) --> O(n^2)

        // return ans;

        int i = 0;

        vector<int> freq(26 , 0);

        for(int j = 0 ; j < n ; j++){
            freq[s[j] - 'A']++;

            int mostFreq = 0;

            for(int e : freq){
                mostFreq = max(mostFreq , e);
            }

            while(i < j && (j-i+1 - mostFreq > k)){
                freq[s[i] - 'A']--;

                for(int e : freq){
                    mostFreq = max(mostFreq , e);
                }
                i++;
            }

            ans = max(ans , j-i+1);
        }

        return ans;
    }
};

/*
    AABCACDA   k = 2
    
*/