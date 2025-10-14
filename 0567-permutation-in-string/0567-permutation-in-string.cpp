class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        /*
            we just need a substring with all charcacter of s1 and no other character 

            brute force --> to check all the substring and match the characters

            better appraoch --> O(n^2)



            

        */
        int n = s2.length();

        vector<int> freqS1(26 , 0);

        for(char ch : s1) freqS1[ch - 'a']++;

        int i = 0;
        vector<int> freqSub(26 , 0);

        for(int j = 0 ; j < n ; j++){
            freqSub[s2[j] - 'a']++;

            while(i < j && freqSub[s2[i] - 'a'] > freqS1[s2[i] - 'a']){
                freqSub[s2[i] - 'a']--;

                i++;
            }
            bool flag = true;
            for(int k = 0 ; k < 26 ; k++){
                if(freqSub[k] != freqS1[k]){
                    flag = false;
                    break;
                }
            }

            if(flag) return true;
             
        }
        // O(26 * n)
        return false;
    }
};