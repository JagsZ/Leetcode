class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       int rowBegin = 0;
       int rowEnd = matrix.size() - 1;
       int columnBegin = 0;
       int columnEnd = matrix[0].size() - 1;
       vector<int> out;
       if(matrix.size() == 0) return out;

        while(rowBegin <= rowEnd && columnBegin <= columnEnd){

            for(int i = columnBegin; i <= columnEnd; i++) {
                    out.push_back(matrix[rowBegin][i]);
            }
            rowBegin++;
            for(int i = rowBegin; i <= rowEnd; i++) {
                out.push_back(matrix[i][columnEnd]);
            }
            columnEnd--;
            if(rowBegin <= rowEnd) {
                for(int i = columnEnd; i >= columnBegin; i--) {
                    out.push_back(matrix[rowEnd][i]);
                }
            }
            rowEnd--;
            if(columnBegin <= columnEnd) {
                for(int i = rowEnd; i >= rowBegin; i--) {
                    out.push_back(matrix[i][columnBegin]);
                }
            }
            columnBegin++;

        }
        return out;  
        }
};