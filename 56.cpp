class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& A) {
        sort(begin(A), end(A));
        vector<vector<int>> ans;
        for (auto &v : A) {
            if (ans.empty() || v[0] > ans.back()[1]) ans.push_back(v);
            else ans.back()[1] = max(ans.back()[1], v[1]);
        }
        return ans;
    }
};