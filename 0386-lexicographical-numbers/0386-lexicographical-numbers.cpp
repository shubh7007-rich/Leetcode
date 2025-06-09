class Solution {
public:
    void func(int num , int n , vector<int>& ans){
        if(num > n) return;
        
        ans.push_back(num);

        for(int i = 0 ; i <= 9 ; i++){
            int temp = num;
            temp = temp * 10 + i;
            if(temp <= n) func(temp , n , ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;

        for(int i = 1 ; i <= 9 ; i++){
            if(i <= n) func(i , n , ans);
        }

        return ans;
    }
};