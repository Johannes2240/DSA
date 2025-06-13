class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& terrain) {
        int height = terrain.size();
        int width = terrain[0].size();
        int maxVal = height + width;
        vector<vector<int>> elevation(height, vector<int>(width, maxVal));

        for (int row = 0; row < height; ++row) {
            for (int col = 0; col < width; ++col) {
                if (terrain[row][col] == 1) {
                    elevation[row][col] = 0;
                }
            }
        }
        for (int row = 0; row < height; ++row) {
            for (int col = 0; col < width; ++col) {
                if (row > 0)
                    elevation[row][col] = min(elevation[row][col], elevation[row - 1][col] + 1);
                if (col > 0)
                    elevation[row][col] = min(elevation[row][col], elevation[row][col - 1] + 1);
            }
        }
        for (int row = height - 1; row >= 0; --row) {
            for (int col = width - 1; col >= 0; --col) {
                if (row < height - 1)
                    elevation[row][col] = min(elevation[row][col], elevation[row + 1][col] + 1);
                if (col < width - 1)
                    elevation[row][col] = min(elevation[row][col], elevation[row][col + 1] + 1);
            }
        }

        return elevation;
    }
}; 
