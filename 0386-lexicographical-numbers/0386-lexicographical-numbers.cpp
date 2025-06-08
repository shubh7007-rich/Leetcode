class Solution {
public:
    void dfs(int num , vector<int>& ans , int n){
        if(num > n) return;
        
        ans.push_back(num);

        for(int i = 0 ; i <= 9 ; i++){
            int temp = num;
            temp = temp * 10 + i;

            if(temp <= n) dfs(temp , ans , n);
        }
    }
    vector<int> lexicalOrder(int n) {
        int num = 1;
        vector<int> ans;

        for(int i = 1 ; i <= 9 ; i++){
            dfs(i , ans , n);
        }

        return ans;
    }
};