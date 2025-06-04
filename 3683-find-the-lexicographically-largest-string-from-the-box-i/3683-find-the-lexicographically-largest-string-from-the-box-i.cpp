class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.length();

        vector<string> vec;

        if(numFriends == 1) return word;

        int len = n - numFriends + 1;

        if(n == numFriends) len = 1;

        for(int i = 0 ; i <= word.length(); i++){
            vec.push_back(word.substr(i , len));
        }
        sort(vec.rbegin() , vec.rend());

        return vec[0];
    }
};