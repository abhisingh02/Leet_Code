class Solution {
public:
    bool isValidBST(TreeNode* root, TreeNode *left = NULL, TreeNode *right = NULL) {
        if (!root) return true;
        if ((left && root->val <= left->val) || (right && root->val >= right->val)) return false;
        return isValidBST(root->left, left, root) && isValidBST(root->right, root, right);
    }
};