// Graph Type: Undirected Graph represented as an Adjacency List 
class Solution {
public:
    void buildGraph(const vector<vector<int>>& isConnected, vector<vector<int>>& adjList) {
        int n = isConnected.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (isConnected[i][j] == 1) {
                    adjList[i].push_back(j);
                    if (i != j) {
                        adjList[j].push_back(i); 
                    }
                }
            }
        }
    }


    void dfs(int city, vector<bool>& visited, const vector<vector<int>>& adjList) {
        visited[city] = true;
        for (int neighbor : adjList[city]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, adjList);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjList(n);
        vector<bool> visited(n, false);

        buildGraph(isConnected, adjList); 

        int provinceCount = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, visited, adjList);
                provinceCount++; 
            }
        }

        return provinceCount;
    }
};
