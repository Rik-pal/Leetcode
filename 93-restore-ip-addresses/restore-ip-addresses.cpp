class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        int n = s.size();

        for (int i = 1; i <= 3; ++i)
            for (int j = i + 1; j <= i + 3; ++j)
                for (int k = j + 1; k <= j + 3; ++k) {
                    if (k >= n) continue;
                    string a = s.substr(0, i),     b = s.substr(i, j - i),
                           c = s.substr(j, k - j), d = s.substr(k);
                    if (valid(a) && valid(b) && valid(c) && valid(d))
                        result.push_back(a + "." + b + "." + c + "." + d);
                }
        return result;
    }
private:
    bool valid(const string& seg) {
        return seg.size() <= 3 && (seg.size() == 1 || seg[0] != '0')
               && stoi(seg) <= 255;
    }
};