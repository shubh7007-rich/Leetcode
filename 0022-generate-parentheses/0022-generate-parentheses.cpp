class Solution {
public:
    bool isValid(string & temp){
        stack<char> st;

        for(char ch : temp){
            if(ch == '('){
                st.push('(');
            }else{
                if(st.empty()) return false;

                st.pop();
            }
        }

        return (st.empty());
    }
    void func(int n ,string & temp ,  vector<string>& ans){
        if(temp.length() == n){
            if(isValid(temp)){
                ans.push_back(temp);
            }
            return;
        }

        temp.push_back('(');
        func(n , temp , ans);
        temp.pop_back();
        temp.push_back(')');
        func(n , temp , ans);
        temp.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        func(2*n ,temp ,  ans);
        return ans;
    }
};