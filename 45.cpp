class Solution {
public:
    int jump(vector<int>& A) {
        int N = A.size();
        vector<int> dp(N, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 1; j <= A[i] && i + j < N; ++j) {
                dp[i + j] = min(dp[i + j], 1 + dp[i]);
            }
        }
        return dp[N - 1];
    }
};