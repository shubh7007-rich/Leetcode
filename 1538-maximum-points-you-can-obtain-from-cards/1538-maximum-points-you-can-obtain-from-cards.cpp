class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // psum n ssum
    
        int psum = 0 , ssum = 0 , n = cardPoints.size() ,  l = k - 1 , r = n-1 ,maxi = 0;

        for(int i = 0 ; i < k ; i++){
            psum += cardPoints[i];
        }

        while(l >= 0){
            maxi = max(psum + ssum , maxi);
            psum -= cardPoints[l];
            l--; 
            ssum += cardPoints[r];
            r--; 
        }
        maxi = max(maxi , ssum);

        return maxi;

    }
};