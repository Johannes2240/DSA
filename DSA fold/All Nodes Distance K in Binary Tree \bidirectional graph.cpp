class Solution {
private:
    void mapParents(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& parentMap, unordered_map<TreeNode*, bool>& visited) {
        if (!node) return;
        visited[node] = false;
        if (node->left) {
            parentMap[node->left] = node;
            mapParents(node->left, parentMap, visited);
        }
        if (node->right) {
            parentMap[node->right] = node;
            mapParents(node->right, parentMap, visited);
        }
    }
    vector<int> findNodesAtDistance(TreeNode* root, TreeNode* start, int dist) {
        unordered_map<TreeNode*, TreeNode*> parentLinks;
        unordered_map<TreeNode*, bool> visitedNodes;
        mapParents(root, parentLinks, visitedNodes);
        queue<pair<TreeNode*, int>> bfsQueue;
        vector<int> result;
        bfsQueue.push({start, 0});
        while (!bfsQueue.empty()) {
            auto [currentNode, currentDist] = bfsQueue.front();
            bfsQueue.pop();

            if (visitedNodes[currentNode]) continue;
            visitedNodes[currentNode] = true;

            if (currentDist == dist) {
                result.push_back(currentNode->val);
                continue;
            }
            if (currentNode->left && !visitedNodes[currentNode->left]) {
                bfsQueue.push({currentNode->left, currentDist + 1});
            }
            if (currentNode->right && !visitedNodes[currentNode->right]) {
                bfsQueue.push({currentNode->right, currentDist + 1});
            }
            if (parentLinks.count(currentNode) && !visitedNodes[parentLinks[currentNode]]) {
                bfsQueue.push({parentLinks[currentNode], currentDist + 1});
            }
        }
        return result;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        return findNodesAtDistance(root, target, k);
    }
};
