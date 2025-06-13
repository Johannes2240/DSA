// Graph used: Binary Tree (a rooted, directed, acyclic graph)
        
class Solution {
public:
    void dfs(TreeNode* node, int parentVal, int grandparentVal, int& total) {
        if (!node) return;

        if (grandparentVal % 2 == 0)
            total += node->val;

        dfs(node->left, node->val, parentVal, total);
        dfs(node->right, node->val, parentVal, total);
    }

    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        dfs(root, -1, -1, sum);
        return sum;
    }
};
