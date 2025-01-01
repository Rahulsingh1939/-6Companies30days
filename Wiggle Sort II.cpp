class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        int n = nums.size();

        auto nth = nums.begin() + n / 2;
        nth_element(nums.begin(), nth, nums.end());
        int median = *nth;

        auto m = [n](int idx)
        { return (2 * idx + 1) % (n | 1); };
        int first = 0, mid = 0, last = n - 1;

        while (mid <= last)
        {
            if (nums[m(mid)] > median)
            {
                swap(nums[m(first)], nums[m(mid)]);
                ++first;
                ++mid;
            }
            else if (nums[m(mid)] < median)
            {
                swap(nums[m(mid)], nums[m(last)]);
                --last;
            }
            else
            {
                ++mid;
            }
        }
    }
};
