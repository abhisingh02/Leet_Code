class Solution {
    set<vector<int>> s;
    vector<int> tmp;
    void dfs(vector<int> &A, int i) {
        if (i == A.size()) {
            s.insert(tmp);
            return;
        }
        dfs(A, i + 1);
        tmp.push_back(A[i]);
        dfs(A, i + 1);
        tmp.pop_back();
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& A) {
        sort(begin(A), end(A));
        dfs(A, 0);
        return vector<vector<int>>(begin(s), end(s));
    }
};