class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int x1 = 1 , x2 = n-1;

        while(true){
            bool f1 = true , f2 = true;
            int t1 = x1 , t2 = x2;
            while(t1){
                if(t1 % 10 == 0){
                    f1 = false;
                    break;
                }
                t1 /= 10;
            }
            while(t2){
                if(t2 % 10 == 0){
                    f2 = false;
                    break;
                }
                t2 /= 10;
            }

            if(!f1 || !f2){
                x1++;
                x2--;
            }else{
                break;
            }
        }

        return {x1 , x2};
    }
};