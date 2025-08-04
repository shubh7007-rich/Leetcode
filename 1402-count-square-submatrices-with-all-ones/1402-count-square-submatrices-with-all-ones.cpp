class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), cnt = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // Only start checking if the cell is 1
                if(matrix[i][j] == 1) {
                    // Try all possible square sizes starting from (i, j)
                    for(int k = 1; i + k <= n && j + k <= m; k++) {
                        bool isSquare = true;

                        // Check all cells in the k x k square
                        for(int x = i; x < i + k; x++) {
                            for(int y = j; y < j + k; y++) {
                                if(matrix[x][y] == 0) {
                                    isSquare = false;
                                    break;
                                }
                            }
                            if(!isSquare) break;
                        }

                        if(isSquare) cnt++;
                        else break; // If one square fails, no need to try larger one
                    }
                }
            }
        }

        return cnt;
    }
};
