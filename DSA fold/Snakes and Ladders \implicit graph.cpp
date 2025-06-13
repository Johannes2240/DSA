class Solution {
public:
    int size;    
    pair<int,int> convertToPosition(int cell) {
        int rowFromBottom = (cell - 1) / size;
        int actualRow = size - 1 - rowFromBottom;
        int col = (cell - 1) % size;      
        bool isRowReversed = ((size % 2 == 1) && (actualRow % 2 == 1)) || 
                             ((size % 2 == 0) && (actualRow % 2 == 0));
        if (isRowReversed) {
            col = size - 1 - col;
        }     
        return {actualRow, col};
    }   
    int snakesAndLadders(vector<vector<int>>& board) {
        size = board.size();
        
        vector<vector<bool>> visited(size, vector<bool>(size, false));
        queue<int> bfsQueue;
        bfsQueue.push(1);    
        visited[size - 1][0] = true;         
        int moves = 0;        
        while (!bfsQueue.empty()) {
            int levelSize = bfsQueue.size();            
            for (int i = 0; i < levelSize; ++i) {
                int currentCell = bfsQueue.front();
                bfsQueue.pop();              
                if (currentCell == size * size) {
                    return moves;
                }                     
                for (int diceRoll = 1; diceRoll <= 6; ++diceRoll) {
                    int nextCell = currentCell + diceRoll;
                    if (nextCell > size * size) break;                  
                    auto [row, col] = convertToPosition(nextCell);
                    if (visited[row][col]) continue;              
                    visited[row][col] = true;
                    if (board[row][col] != -1) {
                        bfsQueue.push(board[row][col]);
                    } else {
                        bfsQueue.push(nextCell);
                    }
                }
            }
            moves++;
        }
        
        return -1; // No path found
    }
};
