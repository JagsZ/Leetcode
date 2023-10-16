class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> triangle(rowIndex+1, vector<int>());
        triangle[0] = {1};
        
        if(rowIndex == 0)
            return triangle[rowIndex];
        
        triangle[1] = {1, 1};
        if(rowIndex == 1)
            return triangle[rowIndex];
        
        for(int i = 2; i <= rowIndex; i++){
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i)
                    triangle[i].push_back(1);
                else
                    triangle[i].push_back(triangle[i-1][j-1] + triangle[i-1][j]);
            }
        }
        return triangle[rowIndex];
    }
};