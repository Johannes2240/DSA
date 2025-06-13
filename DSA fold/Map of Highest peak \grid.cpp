class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows = isWater.size();
        int cols = isWater[0].size();
        int maxDist = rows + cols;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (isWater[r][c] == 1) {
                    isWater[r][c] = 0;
                } else {
                    isWater[r][c] = maxDist;
                }
            }
        }

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (isWater[r][c] != 0) {
                    if (r > 0)
                        isWater[r][c] = min(isWater[r][c], isWater[r - 1][c] + 1);
                    if (c > 0)
                        isWater[r][c] = min(isWater[r][c], isWater[r][c - 1] + 1);
                }
            }
        }

        for (int r = rows - 1; r >= 0; --r) {
            for (int c = cols - 1; c >= 0; --c) {
                if (isWater[r][c] != 0) {
                    if (r < rows - 1)
                        isWater[r][c] = min(isWater[r][c], isWater[r + 1][c] + 1);
                    if (c < cols - 1)
                        isWater[r][c] = min(isWater[r][c], isWater[r][c + 1] + 1);
                }
            }
        }

        return isWater;
    }
};
