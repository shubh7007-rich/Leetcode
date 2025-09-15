class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream ss(text);
        string word = "";
        int c1 = 0 , c2 = 0;
        unordered_set<char> n(brokenLetters.begin() , brokenLetters.end());
        while(ss >> word){
            for(char ch : word){
                if(n.count(ch)){
                    c2++;
                    break;
                }
            }
            c1++;
        }
        return c1 - c2;
    }

}; 