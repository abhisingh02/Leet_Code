class Solution {
    bool isInteger(string s) {
        if (s.empty()) return false;
        int i = 0, N = s.size();
        if (s[i] == '+' || s[i] == '-') ++i;
        if (i == N) return false;
        while (i < N && isdigit(s[i])) ++i;
        return i == N;
    }
    bool isDecimal(string s) {
        if (s.empty()) return false;
        int i = 0, N = s.size();
        if (s[i] == '+' || s[i] == '-') ++i;
        if (i == N) return false;
        bool hasInteger = isdigit(s[i]);
        while (i < N && isdigit(s[i])) ++i;
        if (i == N || s[i] != '.') return false;
        ++i;
        if (i == N) return hasInteger;
        while (i < N && isdigit(s[i])) ++i;
        return i == N;
    }
public:
    bool isNumber(string s) {
        auto eIndex = s.find_first_of("eE");
        if (eIndex == string::npos) return isDecimal(s) || isInteger(s);
        auto first = s.substr(0, eIndex), second = s.substr(eIndex + 1);
        return (isDecimal(first) || isInteger(first)) && isInteger(second);
    }
};