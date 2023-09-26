class Solution {
public:
    int largestRectangleArea(vector<int>& A) {
        int N = A.size(), ans = 0;
        vector<int> prevSmaller(N, -1), nextSmaller(N, N);
        for (int i = N - 2; i >= 0; --i) {
            int j = i + 1;
            while (j < N && A[j] >= A[i]) j = nextSmaller[j];
            nextSmaller[i] = j;
        }
        for (int i = 1; i < N; ++i) {
            int j = i - 1;
            while (j >= 0 && A[j] >= A[i]) j = prevSmaller[j];
            prevSmaller[i] = j;
        }
        for (int i = 0; i < N; ++i) ans = max(ans, (nextSmaller[i] - prevSmaller[i] - 1) * A[i]);
        return ans;
    }
};