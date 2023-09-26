class Solution {
private:
    bool isBalanced(TreeNode* root, int &h) {
        h = 0;
        if (!root) return true;
        int L = 0, R = 0;
        bool b = isBalanced(root->left, L) && isBalanced(root->right, R) && abs(L - R) <= 1;
        h = 1 + max(L, R);
        return b;
    }
public:
    bool isBalanced(TreeNode* root) {
        int h;
        return isBalanced(root, h);
    }
};
