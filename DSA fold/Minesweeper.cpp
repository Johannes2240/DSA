// Graph type: 2D grid graph with 8-directional adjacency (vertical, horizontal, diagonal neighbors)

class Solution {
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int rows = board.size();
        int cols = board[0].size();
        queue<pair<int,int>> q;
        q.push({click[0], click[1]});
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (board[r][c] == 'M') {
                board[r][c] = 'X';
                continue;
            }
            int mineCount = 0;
            vector<pair<int,int>> unrevealedNeighbors;
            for (auto& dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
                if (board[nr][nc] == 'M') {
                    mineCount++;
                } else if (board[nr][nc] == 'E') {
                    unrevealedNeighbors.push_back({nr, nc});
                }
            }
            if (mineCount > 0) {
                board[r][c] = '0' + mineCount;
            } else {
                board[r][c] = 'B'; 
                for (auto& neigh : unrevealedNeighbors) {
                    board[neigh.first][neigh.second] = 'B'; 
                    q.push(neigh);
                }
            }
        }
        return board;
    }
};
