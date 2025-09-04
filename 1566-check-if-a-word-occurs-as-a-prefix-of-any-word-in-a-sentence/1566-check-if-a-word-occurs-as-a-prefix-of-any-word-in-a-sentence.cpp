class Solution {
public:
    int isPrefixOfWord(string sent, string search) {
        stringstream ss(sent);
        string word;

        int len = search.length();
        int i = -1;
        while(ss >> word){
            i++;
            if(word.length() < len) continue;

            if(word.substr(0 , len) == search){
                return i+1;
            }
        }

        return -1;
    }
};