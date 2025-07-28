class Solution {
public:
    bool isPalindrome(int start , int end , string & s){

        while(start < end){
            if(s[start] != s[end]) return false;
            start++;end--;
        }

        return true;
    }
    void func(int ind , vector<string>& temp , vector<vector<string>>& ans , string & s , int n){
        if(ind >= n){
            ans.push_back(temp);
            return;
        }

        for(int i = ind ; i < n ; i++){
            if(isPalindrome(ind , i , s)){
                temp.push_back(s.substr(ind , i-ind+1));
                func(i+1 , temp , ans , s , n);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();

        vector<string> temp;
        vector<vector<string>> ans;

        func(0 , temp , ans , s , n);

        // for(int i = 0 ; i < n ; i++){
        //     if(isPalindrome(0 , i , s)){
        //         temp.push_back(s.substr(0 , i - 0 + 1));
        //         func(i+1 , temp , ans , s , n);
        //         temp.pop_back();
        //     }
        // }

        return ans;
    }
};