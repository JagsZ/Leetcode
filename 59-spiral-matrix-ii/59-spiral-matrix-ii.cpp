class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int count = 1, row_begin = 0, row_end = n-1, col_begin = 0, col_end = n-1;
        vector<vector<int>> ans(n, vector<int>(n, 0));
        
        while(row_begin <= row_end && col_begin <= col_end){
            
            for(int i = col_begin; i <= col_end; i++){
                ans[row_begin][i] = count;
                count++;
            }
            row_begin++;
            
            for(int i = row_begin; i <= row_end; i++){
                ans[i][col_end] = count;
                count++;
            }
            col_end--;
            
            for(int i = col_end; i >= col_begin; i--){
                ans[row_end][i] = count;
                count++;
            }
            row_end--;
            
            for(int i = row_end; i >= row_begin; i--){
                ans[i][col_begin] = count;
                count++;
            }
            col_begin++;
            
        }
        return ans;
    }
};