//Graph type: Binary Search Tree (BST)

class Solution {
public:
    void pushAllLeft(TreeNode* node, stack<TreeNode*>& stk) {
        while (node) {
            stk.push(node);
            node = node->left;
        }
    }
    void exchangeValues(TreeNode* a, TreeNode* b) {
        int tempVal = a->val;
        a->val = b->val;
        b->val = tempVal;
    }
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> stk;
        pushAllLeft(root, stk);
        TreeNode *firstErrorNode = nullptr, *secondErrorNode = nullptr;
        TreeNode* prevNode = nullptr;
        while (!stk.empty()) {
            TreeNode* current = stk.top();
            stk.pop();
            if (prevNode && prevNode->val > current->val) {
                if (!firstErrorNode) {
                    firstErrorNode = prevNode;
                    secondErrorNode = current;
                } else {
                    secondErrorNode = current;
                    break;
                }
            }
            prevNode = current;
            if (current->right) {
                pushAllLeft(current->right, stk);
            }
        }
        if (firstErrorNode && secondErrorNode) {
            exchangeValues(firstErrorNode, secondErrorNode);
        }
    }
};
