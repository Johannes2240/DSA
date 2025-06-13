// Graph Type: Binary Tree

class Solution {
    int calculate(TreeNode* node, string& path) {
        if (!node)
            return 0;

        path.push_back('0' + node->val);

        if (!node->left && !node->right) {
            int num = stoi(path);
            path.pop_back();
            return num;
        }

        int result = 0;
        if (node->left)
            result += calculate(node->left, path);
        if (node->right)
            result += calculate(node->right, path);

        path.pop_back();
        return result;
    }

public:
    int sumNumbers(TreeNode* root) {
        string pathStr;
        return calculate(root, pathStr);
    }
};
