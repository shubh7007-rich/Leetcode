class Solution {
public:
    int inf = 1e7;
    int func(int prev , int len , int n){
        if(len == n){
            return 0;
        }
        if(len > n) return inf;
        int paste = INT_MAX;
        int copy = 2 + func(len , len + len, n);
        if(prev > -1) paste = 1 + func(prev , len + prev , n);

        return min(paste , copy);
    }
    int minSteps(int n) {
        string str = "A";

        if(n == 1) return 0;

        int prev = -1;
        return func(prev , 1 , n);
    }
};