class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int p1 = 0 , p2 = 0 , n1 = word1.length() , n2 = word2.length();
        string ans = "";

        while(p1 < n1 && p2 < n2){
            ans += word1[p1];
            ans += word2[p2];
            p1++;
            p2++;
        }

        while(p1 < n1){
            ans += word1[p1];
            p1++;
        }
        while(p2 < n2){
            ans += word2[p2];
            p2++;
        }

        return ans;

        
    }
};