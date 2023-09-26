class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> target, cnt;
        int len = INT_MAX, i = 0, N = s.size(), matched = 0, begin = 0;
        for (char c : t) target[c]++;
        for (int j = 0; j < N; ++j) {
            if (++cnt[s[j]] <= target[s[j]]) ++matched;
            while (matched == t.size()) {
                if (j - i + 1 < len) {
                    len = j - i + 1;
                    begin = i;
                }
                if (--cnt[s[i]] < target[s[i]]) --matched;
                ++i;
            }
        }
        return len == INT_MAX ? "" : s.substr(begin, len);
    }
};