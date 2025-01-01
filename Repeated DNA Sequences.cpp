class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        if (n < 10)
            return {};
        unordered_map<string, int> um;
        vector<string> res;

        for (int i = 0; i <= n - 10; i++) {
            string tmp = s.substr(i, 10);
            if (um[tmp] > 0) {
                res.emplace_back(tmp);
                um[tmp] = -1 * n;
            } else
                um[tmp]++;
        }
        return res;
    }
};