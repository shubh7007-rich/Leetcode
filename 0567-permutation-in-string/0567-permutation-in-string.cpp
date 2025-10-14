class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        /*
            we just need a substring with all charcacter of s1 and no other character 

            brute force --> to check all the substring and match the characters

            

        */
        int n = s2.length();
        vector<int> freqS1(26 , 0);

        for(char ch : s1) freqS1[ch - 'a']++;

        for(int i = 0 ; i < n ; i++){
            vector<int> freqSub(26 , 0);

            for(int j = i ; j < n ; j++){
                freqSub[s2[j] - 'a']++;
                
                bool flag = true;
                for(int k = 0 ; k < 26 ; k++){
                    if(freqS1[k] != freqSub[k]){
                        flag = false;
                        break;
                    }
                }

                if(flag) return true;
            }
        }

        return false;
    }
};