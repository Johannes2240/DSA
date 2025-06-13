// Graph type: Grid graph (4-directionally connected cells representing land)

class Solution {
public:
    int currentArea;

    void dfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) 
            return;
        grid[i][j] = 0;  // Mark visited
        currentArea++;

        dfs(i - 1, j, grid);
        dfs(i + 1, j, grid);
        dfs(i, j - 1, grid);
        dfs(i, j + 1, grid);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for (int i = 0; i < (int)grid.size(); i++) {
            for (int j = 0; j < (int)grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    currentArea = 0;
                    dfs(i, j, grid);
                    maxArea = max(maxArea, currentArea);
                }
            }
        }
        return maxArea;
    }
};
