// Graph Type: Weighted Directed Graph (Adjacency List)

class Solution {
private:
    double findRatio(const string& src, const string& dst, unordered_map<string, unordered_map<string, double>>& graph) {
        queue<pair<string, double>> toVisit;
        unordered_set<string> seen;
        toVisit.push({src, 1.0});

        while (!toVisit.empty()) {
            auto [curr, product] = toVisit.front();
            toVisit.pop();

            if (curr == dst) return product;

            seen.insert(curr);

            for (const auto& neighbor : graph[curr]) {
                if (!seen.count(neighbor.first)) {
                    toVisit.push({neighbor.first, product * neighbor.second});
                }
            }
        }
        return -1.0;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& inputPairs, vector<double>& ratios, vector<vector<string>>& questions) {
        unordered_map<string, unordered_map<string, double>> connections;

        for (int i = 0; i < inputPairs.size(); ++i) {
            const string& var1 = inputPairs[i][0];
            const string& var2 = inputPairs[i][1];
            double ratio = ratios[i];

            connections[var1][var2] = ratio;
            connections[var2][var1] = 1.0 / ratio;
        }

        vector<double> answers;
        for (const auto& query : questions) {
            const string& from = query[0];
            const string& to = query[1];

            if (!connections.count(from) || !connections.count(to)) {
                answers.push_back(-1.0);
            } else {
                answers.push_back(findRatio(from, to, connections));
            }
        }

        return answers;
    }
};
