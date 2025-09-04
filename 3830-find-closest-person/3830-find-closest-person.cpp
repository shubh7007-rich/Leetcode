class Solution {
public:
    int findClosest(int x, int y, int z) {
        int dist1 = abs(z-x);
        int dist2 = abs(z-y);


        if(dist1 > dist2){
            return 2;
        }else if(dist2 > dist1){
            return 1;
        }

        return 0;
    }
};