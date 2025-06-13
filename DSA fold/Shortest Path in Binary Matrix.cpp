class Solution {
public:
    int shortestClearPath(vector<vector<int>>& matrix) {
        int n = matrix.size();        
        if (matrix[0][0] != 0 || matrix[n - 1][n - 1] != 0) {
            return -1;
        }
        vector<pair<int,int>> moves = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };
        queue<tuple<int,int,int>> traversalQueue;
        traversalQueue.emplace(0, 0, 1);
        matrix[0][0] = 1;
        while (!traversalQueue.empty()) {
            auto [currentRow, currentCol, dist] = traversalQueue.front();
            traversalQueue.pop();
            
            if (currentRow == n - 1 && currentCol == n - 1) {
                return dist;
            }
            for (auto& move : moves) {
                int nextRow = currentRow + move.first;
                int nextCol = currentCol + move.second; 
                if (nextRow >= 0 && nextRow < n &&
                    nextCol >= 0 && nextCol < n &&
                    matrix[nextRow][nextCol] == 0) {
                    matrix[nextRow][nextCol] = 1;
                    traversalQueue.emplace(nextRow, nextCol, dist + 1);
                }
            }
        }
        
        return -1;
    }
};
