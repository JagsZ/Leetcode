class Solution {
    int N=9;
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row(N, unordered_set<char>());
        vector<unordered_set<char>> col(N, unordered_set<char>());
        vector<unordered_set<char>> box(N, unordered_set<char>());
        
        for(int i=0; i<board.size();i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == '.')
                    continue;
                if(row[i].find(board[i][j]) != row[i].end())
                    return false;
                row[i].insert(board[i][j]);
                
                if(col[j].find(board[i][j]) != col[j].end())
                    return false;
                col[j].insert(board[i][j]);
                
                int idx = (i/3)*3+(j/3);
                if(box[idx].find(board[i][j]) != box[idx].end())
                    return false;
                box[idx].insert(board[i][j]);
            }
        }
        return true;
    }
};