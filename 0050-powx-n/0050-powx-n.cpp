class Solution {
public:
    double myPow(double x, long n) {
        double result = 1 , a = x;
        bool flag = false;
        if(n < 0) flag = true;
        n = abs(n);

        while(n){
            if(n&1){
                result *= a;
            }
            a = (a * a);
            n >>= 1;
        }

        if(flag) return 1 / result;

        return result;
    }
};