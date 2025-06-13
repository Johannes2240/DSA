class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows = isWater.size();
        int cols = isWater[0].size();
        int maxDist = rows + cols;

        // Step 1: Mark land cells as maxDist and water cells as 0
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (isWater[r][c] == 1) {
                    isWater[r][c] = 0;
                } else {
                    isWater[r][c] = maxDist;
                }
            }
        }

        // Step 2: Forward pass (top-left to bottom-right)
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

        // Step 3: Backward pass (bottom-right to top-left)
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
