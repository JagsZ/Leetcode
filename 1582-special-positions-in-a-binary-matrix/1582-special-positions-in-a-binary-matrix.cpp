class Solution {
public:
    bool row_col_check(vector<vector<int>>& mat, int row, int col){
        for(int i = 0; i < mat[0].size(); i++){
            if(mat[row][i] == 1 && i != col)
                return false;
        }
        for(int i = 0; i < mat.size(); i++){
            if(mat[i][col] == 1 && i != row)
                return false;
        }
        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), count = 0;
        
        for(int i=0; i < m; i++){
            for(int j=0; j < n && i < m; j++){
                if(mat[i][j] == 1 && row_col_check(mat, i, j)){
                    count++;
                }
            }
        }
        return count;
    }
};