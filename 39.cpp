class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        sort(begin(A), end(A));
        function<void(int, int)> dfs = [&](int start, int goal) {
            if (goal == 0) {
                ans.push_back(tmp);
            }
            for (int i = start; i < A.size() && gaol - A[i] >= 0; ++i) {
                tmp.push_back(A[i]);
                dfs(i, goal - A[i]);
                tmp.pop_back();
            }
        };
        dfs(0, target);
        return ans;
    }
};