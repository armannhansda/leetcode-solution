class Solution {
public:
    int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void dfs(vector<vector<int>>& height, int r, int c, vector<vector<bool>>& ocean){

        ocean[r][c] = true;


        for(auto& dir: dirs){
            int nr = r+ dir[0], nc = c+dir[1];

            if(nr>=0 && nr< height.size() && nc>= 0 && nc<height[0].size() && !ocean[nr][nc] && height[nr][nc] >= height[r][c]){
                dfs(height, nr, nc, ocean);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int r = heights.size();
        int c = heights[0].size();

        vector<vector<bool>> paci(r, vector<bool>(c, false));
        vector<vector<bool>> alt(r, vector<bool>(c, false));

        for(int i = 0; i<c; i++){
            dfs(heights, 0, i, paci);
            dfs(heights, r-1, i, alt);
        }

        for(int i = 0; i<r; i++){
            dfs(heights, i, 0, paci);
            dfs(heights, i, c-1, alt);
        }

        vector<vector<int>> res;

        for(int i =0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(paci[i][j] && alt[i][j]){
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};