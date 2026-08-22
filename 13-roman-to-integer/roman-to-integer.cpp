class Solution {
public:
    int romanToInt(string s) {
        int val[128] = {0};
        val['I'] = 1;
        val['V'] = 5;
        val['X'] = 10;
        val['L'] = 50;
        val['C'] = 100;
        val['D'] = 500;
        val['M'] = 1000;

        int result = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int curr = val[s[i]];
            if (i + 1 < n && curr < val[s[i + 1]]) {
                result -= curr;
            } else {
                result += curr;
            }
        }

        return result;
    }
};