class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        istringstream ss(path);
        string s, ans;
        while (getline(ss, s, '/')) {
            if (s == "..") { 
                if (v.size()) v.pop_back();
            } else if (s.size() && s != ".") v.push_back(s);
        }
        for (auto &p : v) ans += '/' + p;
        return ans.size() ? ans : "/";
    }
};