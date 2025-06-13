// Graph Type: Grid graph with BFS traversal for connected components

class Solution {
    void exploreBoundaryRegion(vector<vector<char>>& board, vector<vector<char>>& marked, int r, int c) {
        int rows = board.size();
        int cols = board[0].size();

        marked[r][c] = 'O';
        queue<pair<int, int>> q;
        q.push({r, c});

        int dirR[] = {-1, 0, 0, 1};
        int dirC[] = {0, -1, 1, 0};

        while (!q.empty()) {
            auto [currR, currC] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int newR = currR + dirR[i];
                int newC = currC + dirC[i];

                if (newR >= 0 && newR < rows && newC >= 0 && newC < cols 
                    && board[newR][newC] == 'O' && marked[newR][newC] != 'O') {
                    marked[newR][newC] = 'O';
                    q.push({newR, newC});
                }
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;

        int m = board.size();
        int n = board[0].size();
        vector<vector<char>> marked(m, vector<char>(n, 'X'));

        // Mark all 'O's connected to the boundary
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && board[i][j] == 'O') {
                    exploreBoundaryRegion(board, marked, i, j);
                }
            }
        }

        // Replace all 'O's that are not marked as connected to boundary with 'X'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = marked[i][j];
            }
        }
    }
};
