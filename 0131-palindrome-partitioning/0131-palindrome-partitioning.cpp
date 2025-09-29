class Solution {
public:
    bool isPalindrome(int l , int r , string & s){
        while(l <= r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void func(int start , string& s , vector<string>& temp , vector<vector<string>>& ans){
        if(start >= s.length()){
            ans.push_back(temp);
            return;
        }

        for(int i = start ; i < s.length() ; i++){
            if(isPalindrome(start , i , s)){
                temp.push_back(s.substr(start , i-start+1));
                func(i+1 , s , temp , ans);
                temp.pop_back();
            }
            
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        for(int i = 0 ; i < s.length() ; i++){
            if(isPalindrome(0 , i , s)){
                temp.push_back(s.substr(0 , i+1));
                func(i+1 , s , temp , ans);
                temp.pop_back();
            }
        }

        return ans;
    }
};