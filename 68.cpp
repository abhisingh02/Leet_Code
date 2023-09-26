class Solution {
public:
    vector<string> fullJustify(vector<string>& A, int maxWidth) {
        int i = 0, j = 0, N = A.size();
        vector<string> ans;
        while (j < N) {
            int width = A[j++].size();
            for (; j < N && width + A[j].size() + 1 <= maxWidth; ++j) {
                width += A[j].size() + 1;
            }
            int cnt = j - i, space = maxWidth - width + (cnt - 1), d, r;
            if (cnt > 1) {
                d = space / (cnt - 1);
                r = space % (cnt - 1);
            }
            ans.emplace_back();
            for (; i < j; ++i) {
                ans.back() += A[i];
                if (j == N || cnt == 1) {
                    if (i < j - 1) ans.back() += ' ';
                    else {
                        while (ans.back().size() < maxWidth) ans.back() += ' ';
                    }
                } else if (i < j - 1) {
                    for (int k = 0; k < d; ++k) {
                        ans.back() += ' ';
                    }
                    if (r > 0) {
                        ans.back() += ' ';
                        --r;
                    }
                }
            }
        }
        return ans;
    }
};