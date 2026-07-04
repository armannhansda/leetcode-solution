class Solution {
public:
    // vector<vector<bool>>& vis;
    void dfs(vector<vector<char>>& board, int r, int c,vector<vector<bool>>& vis){
        if(r<0|| c<0|| r>=board.size() || c>= board[0].size() || vis[r][c] || board[r][c] == 'X') return;

        vis[r][c] = true;

        dfs(board, r+1, c, vis);
        dfs(board, r-1, c, vis);
        dfs(board, r, c+1, vis);
        dfs(board, r, c-1, vis);
    }
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        if(r==0) return;
        int c = board[0].size();

        vector<vector<bool>>vis(r, vector<bool>(c, false));

        for(int i =0; i<r; i++){
            if(board[i][0]== 'O') dfs(board, i, 0, vis);
            if(board[i][c-1]== 'O') dfs(board, i, c-1, vis);
        }
        for(int i =0; i<c; i++){
            if(board[0][i]== 'O') dfs(board, 0, i, vis);
            if(board[r-1][i]== 'O') dfs(board, r-1, i, vis);
        }

        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
