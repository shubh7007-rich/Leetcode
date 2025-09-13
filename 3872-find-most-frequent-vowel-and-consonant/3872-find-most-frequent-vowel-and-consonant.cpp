class Solution {
public:
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    int maxFreqSum(string s) {
        unordered_map<char , int> freq;

        int m1 = 0 , m2 = 0;

        for(char ch : s){
            freq[ch]++;

            if(isVowel(ch)){
                m1 = max(m1 , freq[ch]);
            }else{
                m2 = max(m2 , freq[ch]);
            }
        }

        return m2 + m1;
    }
};