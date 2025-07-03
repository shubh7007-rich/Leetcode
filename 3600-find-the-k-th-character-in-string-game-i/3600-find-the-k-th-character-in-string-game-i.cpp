class Solution {
public:
    string next(string word){
        for(int i = 0 ; i < word.length() ; i++){
            if(word[i] == 'z'){
                word[i] = 'a';
            }else{
                word[i] += 1;
            }
        }

        return word;
    }
    char kthCharacter(int k) {
        string word = "a";

        while(word.length() < k){
            word += next(word);
        }

        return word[k-1];
    }
};