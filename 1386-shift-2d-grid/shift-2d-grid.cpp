class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        
        // Effective shifts needed
        k = k % total;
        
        vector<vector<int>> result(m, vector<int>(n));
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                // Calculate original flat index for result[r][c]
                int flat_idx = r * n + c;
                int original_flat_idx = (flat_idx - k + total) % total;
                
                int orig_r = original_flat_idx / n;
                int orig_c = original_flat_idx % n;
                
                result[r][c] = grid[orig_r][orig_c];
            }
        }
        
        return result;
    }
};