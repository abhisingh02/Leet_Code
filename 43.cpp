class Solution {
    string mul(const string &a, int n, int shift) {
        if (n == 0 || a == "0") return "0";
        int carry = 0;
        string ans;
        for (int N = a.size(), i = N - 1; i >= 0 || carry;) {
            if (i >= 0) carry += (a[i--] - '0') * n;
            ans += carry % 10 + '0';
            carry /= 10;
        }
        reverse(begin(ans), end(ans));
        while (shift--) ans += '0';
        return ans;
    }
    string add(string a, string b) {
        if (a == "0") return b;
        if (b == "0") return a;
        string ans;
        for (int i = a.size() - 1, j = b.size() - 1, carry = 0; i >= 0 || j >= 0 || carry; ) {
            if (i >= 0) carry += a[i--] - '0';
            if (j >= 0) carry += b[j--] - '0';
            ans += carry % 10 + '0';
            carry /= 10;
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
public:
    string multiply(string a, string b) {
        string ans = "0";
        for (int i = 0, N = b.size(); i < N; ++i) {
            ans = add(ans, mul(a, b[N - 1 - i] - '0', i));
        }
        return ans;
    }
};