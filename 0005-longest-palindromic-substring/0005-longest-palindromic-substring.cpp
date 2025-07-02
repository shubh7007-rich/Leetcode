class Solution {
public:
    
    string longestPalindrome(string s) {
        int n = s.length(), maxi = 0;
        string ans = "";
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                // string str = s.substr(i , j-i+1);

                // if(isPalindrome(str)){
                //     if(str.length() > maxi){
                //         maxi = str.length();
                //         ans = str;
                //     }
                // }
                int l = i, r = j;
                bool p = true;

                while (l <= r) {
                    if (s[l] != s[r]){
                        p = false;
                        break;
                    }
                    l++;
                    r--;
                }

                if(p && (j-i+1 > maxi)){
                    maxi = j-i+1;
                    ans = s.substr(i , j-i+1);
                }
            }
        }

        return ans;
    }
};