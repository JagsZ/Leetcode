class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        int m = matrix.size(), n = matrix[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int row = i+1;
                int col = j+1;
                if((row < m && col < n) && matrix[i][j] != matrix[row][col])
                    return false;
            }
        }
        return true;
    }
};