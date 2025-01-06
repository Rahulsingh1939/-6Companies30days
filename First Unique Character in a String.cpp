class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        vector<int> um(26, 0);
        for (auto ch : s) {
            um[ch - 'a']++;
        }
        for (int i = 0; i < n; i++) {
            if (um[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};