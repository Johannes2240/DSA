//Grid graph
class Solution {
public:
    int maxDistance(vector<vector<int>>& map) {
        int size = map.size();
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> bfsQueue;
        for (int row = 0; row < size; ++row) {
            for (int col = 0; col < size; ++col) {
                if (map[row][col] == 1) {
                    bfsQueue.push({row, col});
                }
            }
        }
        if (bfsQueue.empty() || bfsQueue.size() == size * size)
            return -1;

        int maxDist = -1;
        while (!bfsQueue.empty()) {
            auto [currRow, currCol] = bfsQueue.front();
            bfsQueue.pop();

            for (auto [dRow, dCol] : directions) {
                int newRow = currRow + dRow;
                int newCol = currCol + dCol;
                if (newRow < 0 || newRow >= size || newCol < 0 || newCol >= size || map[newRow][newCol] != 0)
                    continue;
                map[newRow][newCol] = map[currRow][currCol] + 1;
                maxDist = max(maxDist, map[newRow][newCol]);
                bfsQueue.push({newRow, newCol});
            }
        }
        return maxDist - 1;
    }
};
