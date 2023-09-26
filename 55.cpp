class Solution {
public:
    bool canJump(vector<int>& A) {
        for (int i = 0, last = 0; i <= last; ++i) {
            last = max(last, i + A[i]);
            if (last >= A.size() - 1) return true;
        }
        return false;
    }
};