int adj_row[] = {0, 1, 0, -1};
int adj_col[] = {1, 0, -1, 0};
class Solution {
    bool solve(vector<vector<char>>& board, int row, int col, string &board_str, string &word, 
               int m, int n, vector<vector<bool>> &vis){
        if(board_str == word)
            return true;

        if(board_str.length() >= word.length())
            return false;
        
        for(int i = 0; i < 4; i ++){
            int nrow = row + adj_row[i];
            int ncol = col + adj_col[i];
            if((nrow >= 0 && nrow < m) && (ncol >= 0 && ncol < n) && vis[nrow][ncol] == false){
                board_str += board[nrow][ncol];
                vis[nrow][ncol] = true;
                if(solve(board, nrow, ncol, board_str, word, m, n, vis) == true)
                    return true;
                board_str.pop_back();
                vis[nrow][ncol] = false;
            }
        }
        return false;   
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        
        for(int i = 0; i  < m; i++){
            for(int j = 0; j < n ; j ++){
                vector<vector<bool>> vis(m, vector<bool>(n, false));
                string board_str = "";
                if(board[i][j] == word[0]){
                    board_str += board[i][j];
                    vis[i][j] = true;
                    if(solve(board, i, j, board_str, word, m, n, vis) == true)
                        return true;
                }
            }
        }
        return false;
    }
};