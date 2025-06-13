class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        vector<vector<int>> dist(rows, vector<int>(cols, 1e9));
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (mat[r][c] == 0) {
                    dist[r][c] = 0;
                } else {
                    if (r > 0)
                        dist[r][c] = min(dist[r][c], dist[r - 1][c] + 1);
                    if (c > 0)
                        dist[r][c] = min(dist[r][c], dist[r][c - 1] + 1);
                }
            }
        }
        for (int r = rows - 1; r >= 0; --r) {
            for (int c = cols - 1; c >= 0; --c) {
                if (r < rows - 1)
                    dist[r][c] = min(dist[r][c], dist[r + 1][c] + 1);
                if (c < cols - 1)
                    dist[r][c] = min(dist[r][c], dist[r][c + 1] + 1);
            }
        }

        return dist;
    }
};
