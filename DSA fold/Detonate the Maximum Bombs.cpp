// Graph Type: Directed Graph
class Solution {
public:
    int explore(int total, vector<vector<int>>& data, int start) {
        int exploded = 1;
        vector<bool> seen(total, false);
        seen[start] = true;

        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            long long cx = data[current][0];
            long long cy = data[current][1];
            long long radius = data[current][2];

            for (int j = 0; j < total; ++j) {
                if (!seen[j]) {
                    long long tx = data[j][0];
                    long long ty = data[j][1];

                    long long distSquared = (cx - tx) * (cx - tx) + (cy - ty) * (cy - ty);
                    if (distSquared <= radius * radius) {
                        seen[j] = true;
                        ++exploded;
                        q.push(j);
                    }
                }
            }
        }

        return exploded;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        int maxCount = 1;

        for (int i = 0; i < n; ++i) {
            maxCount = max(maxCount, explore(n, bombs, i));
            if (maxCount == n) break; // Early termination if all bombs can be detonated
        }

        return maxCount;
    }
};
