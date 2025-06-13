//Undirected grid graph
class Solution {
public:
    vector<vector<int>> moves = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    
    int nearestExit(vector<vector<char>>& labyrinth, vector<int>& startPos) {
        int rows = labyrinth.size();
        int cols = labyrinth[0].size();
        queue<pair<int,int>> bfsQueue;
        bfsQueue.push({startPos[0], startPos[1]});
        labyrinth[startPos[0]][startPos[1]] = '+'; 
        int stepsTaken = 0;
        int shortestExitDistance = INT_MAX;
        while (!bfsQueue.empty()) {
            int currentLevelSize = bfsQueue.size();
            stepsTaken++;

            for (int i = 0; i < currentLevelSize; i++) {
                auto [currRow, currCol] = bfsQueue.front();
                bfsQueue.pop();

                for (auto& direction : moves) {
                    int nextRow = currRow + direction[0];
                    int nextCol = currCol + direction[1];

                    if (nextRow < 0 || nextRow >= rows || nextCol < 0 || nextCol >= cols) continue;
                    if (labyrinth[nextRow][nextCol] == '+') continue;

                    if (nextRow == 0 || nextRow == rows - 1 || nextCol == 0 || nextCol == cols - 1) {
                        if (labyrinth[nextRow][nextCol] == '.') {
                            shortestExitDistance = min(shortestExitDistance, stepsTaken);
                        }
                        continue;
                    }

                    labyrinth[nextRow][nextCol] = '+';
                    bfsQueue.push({nextRow, nextCol});
                }
            }
        }

        return shortestExitDistance == INT_MAX ? -1 : shortestExitDistance;
    }
};
