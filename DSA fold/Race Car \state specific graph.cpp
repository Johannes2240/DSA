//State specific graph
class Solution {
public:
    int racecar(int target) {
        queue<vector<long long>> pending;
        unordered_map<long long, unordered_set<long long>> visited;

        pending.push({0, 1, 0});

        while (!pending.empty()) {
            auto state = pending.front();
            pending.pop();

            long long pos = state[0];
            long long vel = state[1];
            long long cnt = state[2];

            if (pos == target) return cnt;

            if (visited[pos].count(vel)) continue;
            visited[pos].insert(vel);

            pending.push({pos + vel, vel * 2, cnt + 1});

            if ((pos + vel > target && vel > 0) || (pos + vel < target && vel < 0)) {
                long long newVel = vel > 0 ? -1 : 1;
                pending.push({pos, newVel, cnt + 1});
            }
        }

        return -1;
    }
};
