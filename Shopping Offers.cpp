class Solution {
public:
    int solve(vector<int>& price, vector<vector<int>>& special,
              vector<int> needs, int index, unordered_map<string, int>& memo) {
        string key = to_string(index) + "-" + to_string(needs[0]);
        for (int i = 1; i < needs.size(); i++) {
            key += "," + to_string(needs[i]);
        }
        if (memo.count(key))
            return memo[key];

        if (index == special.size()) {
            int res = 0;
            for (int i = 0; i < needs.size(); i++) {
                res += needs[i] * price[i];
            }
            return res;
        }

        // Reject current special offer
        int reject = solve(price, special, needs, index + 1, memo);
        vector<int> newNeeds = needs;
        bool valid = true;
        for (int i = 0; i < needs.size(); i++) {
            newNeeds[i] -= special[index][i];
            if (newNeeds[i] < 0) {
                valid = false;
                break;
            }
        }

        int accept = INT_MAX;
        if (valid) {
            accept = special[index][needs.size()] +
                     solve(price, special, newNeeds, index, memo);
        }

        return memo[key] = min(accept, reject);
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special,
                       vector<int>& needs) {
        unordered_map<string, int> memo;
        return solve(price, special, needs, 0, memo);
    }
};
