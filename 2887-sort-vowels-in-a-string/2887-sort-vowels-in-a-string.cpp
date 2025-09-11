class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;

        return false;
    }
    string sortVowels(string s) {
        vector<char> chr;

        for(char ch : s){
            if(isVowel(tolower(ch))){
                chr.push_back(ch);
            }
        }
        int p = 0;
        sort(chr.begin() , chr.end());

        for(char & ch : s){
            if(isVowel(tolower(ch))){
                ch = chr[p];
                p++;
            }
        }

        return s;
    }
};