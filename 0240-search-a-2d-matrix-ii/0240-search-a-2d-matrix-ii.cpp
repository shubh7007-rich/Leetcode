class Solution {
public:
    bool bs(int size , vector<int> & matrix, int target){
        int l = 0 , r = size - 1;

        while(l <= r){
            int mid = (l+r)/2;

            if(matrix[mid] == target){
                return true;
            }else if(matrix[mid] > target){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix[0].size();

        for(vector<int>& vec : matrix){
            if(bs(m , vec , target)){
                return true;
            }
        }

        return false;
    }
};