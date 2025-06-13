//Graph type used: Binary Tree


class Solution {
public:
    TreeNode* lowestCommonAncestorOfDeepestLeaves(TreeNode* root) {
        vector<pair<TreeNode*, int>> leavesWithDepths;
        collectLeaves(root, leavesWithDepths, 0);
        int maxDepth = INT_MIN;
        for (auto& nodeDepthPair : leavesWithDepths) {
            if (nodeDepthPair.second > maxDepth) {
                maxDepth = nodeDepthPair.second;
            }
        }
        vector<TreeNode*> deepestLeaves;
        for (auto& nodeDepthPair : leavesWithDepths) {
            if (nodeDepthPair.second == maxDepth) {
                deepestLeaves.push_back(nodeDepthPair.first);
            }
        }

        TreeNode* ancestor = deepestLeaves[0];
        for (int i = 1; i < (int)deepestLeaves.size(); ++i) {
            ancestor = findCommonAncestor(root, ancestor, deepestLeaves[i]);
        }
        return ancestor;
    }
private:
    TreeNode* collectLeaves(TreeNode* node, vector<pair<TreeNode*, int>>& collected, int depth) {
        if (!node) return nullptr;
        TreeNode* leftChild = collectLeaves(node->left, collected, depth + 1);
        TreeNode* rightChild = collectLeaves(node->right, collected, depth + 1);

        if (!leftChild && !rightChild) {
            collected.push_back({node, depth});
            return node;
        }
        return leftChild ? leftChild : rightChild;
    }
    TreeNode* findCommonAncestor(TreeNode* root, TreeNode* a, TreeNode* b) {
        if (!root || root == a || root == b) return root;
        TreeNode* leftSide = findCommonAncestor(root->left, a, b);
        TreeNode* rightSide = findCommonAncestor(root->right, a, b);

        if (leftSide && rightSide) return root;
        return leftSide ? leftSide : rightSide;
    }
};
