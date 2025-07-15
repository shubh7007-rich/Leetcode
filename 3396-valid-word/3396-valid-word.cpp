class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }

    bool isValid(string word) {
        if(word.length() >= 3){
            int v = 0 , c = 0 , n = 0 , d = 0;

            for(char ch : word){
                if(isVowel(ch)){
                    v++;
                }else if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z'){
                    c++;
                }else if(ch >= '0' && ch <= '9'){
                    d++;
                }else{
                    return false;
                }
            }

            if(v >= 1 && c >= 1) return true;

            return false;
        }

        return false;
    }
};