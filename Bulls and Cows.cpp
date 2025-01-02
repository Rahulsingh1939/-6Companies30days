class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        unordered_map<char, int> um;
        int x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i])
                x++;
            else {
                um[secret[i]]++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (secret[i] != guess[i]) {
                if (um.find(guess[i]) != um.end()) {
                    y++;
                    um[guess[i]]--;
                    if (um[guess[i]] == 0)
                        um.erase(guess[i]);
                }
            }
        }
        string res = to_string(x) + 'A' + to_string(y) + 'B';
        return res;
    }
};