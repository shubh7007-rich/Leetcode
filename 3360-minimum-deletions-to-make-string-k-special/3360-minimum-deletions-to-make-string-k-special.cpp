class Solution {
public:
    int minimumDeletions(string word, int k) {
        int ans = INT_MAX;
        vector<int> freq(26 , 0);

        for(char & ch : word){
            freq[ch-'a']++;
        }
        // yahe pe phele i tried it jo maxi freq wala hoga usko kam krenge - didn't work
        // then mini wale ko - didn't work
        // then whoever closer to average of all the freq - didn't work
        // so the last option is consider every char as miniCh with miniFreq , so we can have characters with freq in the range [miniFreq , miniFreq+k]

        for(int i = 0 ; i < 26 ; i++){
            if(freq[i] != 0){
                int miniFreq = freq[i];
                int maxiFreq = miniFreq + k;

                int mini = 0;

                for(int i = 0 ; i < 26 ; i++){
                    if(freq[i] < miniFreq){
                        mini += freq[i];
                    }

                    if(freq[i] > maxiFreq){
                        mini += (freq[i] - maxiFreq);
                    }
                }

                ans = min(mini , ans);
            }
        }

        return ans;
    }
};