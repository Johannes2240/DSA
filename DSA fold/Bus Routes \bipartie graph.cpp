class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        // Mark each stop with a large initial value (unreachable)
        const int INF = 500;
        vector<int> minBuses(1e6, INF);
        minBuses[source] = 0;

        int unchangedRounds = 0;
        int prevTargetVal = INF;

        while (unchangedRounds <= 2) {
            for (const auto& route : routes) {
                int minOnRoute = INF;
                for (int stop : route) {
                    if (minBuses[stop] < minOnRoute) {
                        minOnRoute = minBuses[stop] + 1;
                    }
                    if (stop == source) {
                        minOnRoute = 1;
                        break;
                    }
                }
                for (int stop : route) {
                    if (minBuses[stop] > minOnRoute) {
                        minBuses[stop] = minOnRoute;
                    }
                }
            }

            if (minBuses[target] < prevTargetVal) {
                prevTargetVal = minBuses[target];
                unchangedRounds = 0;
            } else {
                ++unchangedRounds;
            }
        }

        return minBuses[target] == INF ? -1 : minBuses[target];
    }
};
