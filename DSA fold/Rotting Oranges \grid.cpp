
class Solution {
public:
    using Coord = pair<int, int>;
    vector<Coord> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<Coord> rottenQueue;
        int freshCount = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 2) {
                    rottenQueue.push({r, c});
                } else if (grid[r][c] == 1) {
                    freshCount++;
                }
            }
        }
        if (freshCount == 0) return 0;
        int minutesPassed = 0;
        while (!rottenQueue.empty()) {
            int levelSize = rottenQueue.size();
            bool rottenThisRound = false;
            for (int i = 0; i < levelSize; i++) {
                auto [x, y] = rottenQueue.front();
                rottenQueue.pop();
                for (auto& dir : directions) {
                    int nx = x + dir.first;
                    int ny = y + dir.second;
                    if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        freshCount--;
                        rottenQueue.push({nx, ny});
                        rottenThisRound = true;
                    }
                }
            }
            if (rottenThisRound) minutesPassed++;
        }
        return freshCount == 0 ? minutesPassed : -1;
    }
};
