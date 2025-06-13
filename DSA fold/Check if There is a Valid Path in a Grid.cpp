//Graph Type: Grid Graph with directional edges based on street types
class Solution {
public:
    vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};  
    unordered_map<int, int> allowedTurns[7] = {
        {},                   
        {{0, 0}, {1, 1}},       
        {{2, 2}, {3, 3}},       
        {{0, 2}, {3, 1}},     
        {{3, 0}, {1, 2}},      
        {{0, 3}, {2, 1}},     
        {{2, 0}, {1, 3}}      
    };
    bool walkPath(vector<vector<int>>& grid, int startDir) {
        int row = 0, col = 0;
        int m = grid.size(), n = grid[0].size();
        while (row >= 0 && col >= 0 && row < m && col < n) {
            int cellType = grid[row][col]; 
            if (allowedTurns[cellType].count(startDir) == 0) {
                return false; 
            }        
            if (row == m - 1 && col == n - 1) {
                return true;
            }          
            startDir = allowedTurns[cellType][startDir];
            row += directions[startDir].first;
            col += directions[startDir].second;
            if (row == 0 && col == 0) {
                return false;
            }
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        return walkPath(grid, 0) || walkPath(grid, 1) || walkPath(grid, 2) || walkPath(grid, 3);
    }
};
