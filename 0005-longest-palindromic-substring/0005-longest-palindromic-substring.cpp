class Solution {
public:
    string longestPalindrome(string s) {
        string str ;
        int maxlen = INT_MIN;
        for(int i = 0 ; i < s.length() ; i++){
            for(int j = i ; j < s.length() ; j++){
                bool isPalindrome = true;
                int left = i ;
                int right = j;
                int len = right - left + 1;
                while(left <= right){
                    if(s[left] != s[right]){
                        isPalindrome = false;
                        break;
                    }
                    left++;
                    right--;
                }
                if(isPalindrome && len > maxlen){
                    maxlen = len;
                    str = s.substr(i , len);
                }
            }
        }
        return str;
    }
};