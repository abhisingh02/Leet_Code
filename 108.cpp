class Solution {
    TreeNode *dfs(vector<int> &A, int begin, int end) {
        if (begin + 1 > end) return NULL;
        int mid = (begin + end) / 2;
        auto root = new TreeNode(A[mid]);
        root->left = dfs(A, begin, mid);
        root->right = dfs(A, mid + 1, end);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& A) {
        return dfs(A, 0, A.size());
    }
};