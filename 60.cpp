class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        for (int i = 0; i < n; ++i) ans += ('1' + i);
        while (--k) next_permutation(begin(ans), end(ans));
        return ans;
    }
};