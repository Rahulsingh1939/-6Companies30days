class Solution {
private:
    int lesSum(vector<int>& nums, int k) {
        if (k < 0)
            return 0;
        int n = nums.size();
        int l = 0, r = 0, od = 0, res = 0;
        while (r < n) {
            if (nums[r] % 2 == 1)
                od++;
            while (od > k) {
                if (nums[l] % 2 == 1)
                    od--;
                l++;
            }
            if (od <= k)
                res+= (r - l + 1);
            r++;
        }
        return res;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return lesSum(nums, k) - lesSum(nums, k - 1);
    }
};