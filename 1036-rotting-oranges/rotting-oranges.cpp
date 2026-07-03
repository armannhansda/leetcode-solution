class Solution {
public:
    int dirs[4][2] ={{1,0}, {-1,0}, {0,1}, {0,-1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 2) q.push({i, j});
                else if(grid[i][j] == 1) fresh++;
            }
        }
        
        if(fresh == 0) return 0;
        int minutes = -1;
        
        while(!q.empty()){
            int size = q.size();
            minutes++;
            while(size--){
                pair<int, int> curr = q.front(); q.pop();
                for(auto& dir: dirs){
                    int nr = curr.first + dir[0], nc = curr.second + dir[1];
                    if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
        }
        
        return fresh == 0 ? minutes : -1;
    }
};
