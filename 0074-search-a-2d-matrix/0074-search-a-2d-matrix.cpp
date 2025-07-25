class Solution {
public:
    // bool bs(int target , vector<int>& arr , int n){
    //     int l = 0 , r = n-1;

    //     while(l <= r){
    //         int mid = l + (r-l)/2;

    //         if(arr[mid] == target){
    //             return true;
    //         }else if(arr[mid] > target){
    //             r = mid - 1;
    //         }else{
    //             l = mid+1;
    //         }
    //     }

    //     return false;
    // }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size() , n = matrix[0].size();

        /*
            Better
            T.C - O(m * log(n))
            for(vector<int>& vec : matrix){
                bool ans =  bs(target , vec , len);
                if(ans) return true;
            }

            optimized better
            T.C - O(m) + log(n)
            for(int i = 0 ; i < m ; i++){
                if(matrix[i][0] <= target && target <= matrix[i][n-1]){
                    return bs(target , matrix[i] , n);
                }
            }

        */
            // Optimal

            int l = 0 , r = m*n - 1;

            while(l <= r){
                int mid = (l + r)/2;

                int row = mid / n , col = mid % n;

                if(matrix[row][col] == target){
                    return true;
                }else if(matrix[row][col] > target){
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }
        

        return false;
    }
}; 