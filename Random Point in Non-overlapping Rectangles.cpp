class Solution {
public:
    vector<int> prefix;
    vector<vector<int>> recs;
    Solution(vector<vector<int>>& rects) {
        int n = rects.size();
        prefix.push_back((rects[0][2] - rects[0][0] + 1) *
                         (rects[0][3] - rects[0][1] + 1));

        for (int i = 1; i < n; i++) {
            prefix.push_back(prefix.back() + ((rects[i][2] - rects[i][0] + 1) *
                                              (rects[i][3] - rects[i][1] + 1)));
        }
        recs = rects;
    }

    vector<int> pick() {
        int rect = rand() % prefix.back();
        int ind =
            upper_bound(prefix.begin(), prefix.end(), rect) - prefix.begin();
        return {recs[ind][0] + rand() % (recs[ind][2] - recs[ind][0] + 1),
                recs[ind][1] + rand() % (recs[ind][3] - recs[ind][1] + 1)};
    }
};
