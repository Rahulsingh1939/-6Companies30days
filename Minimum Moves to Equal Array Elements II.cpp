class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int med = nums[n / 2];
        int res = 0;
        for (int i = 0; i < n; i++)
            res += abs(med - nums[i]);
        return res;
    }
};