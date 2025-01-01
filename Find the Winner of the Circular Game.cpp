class Solution
{
public:
    int findTheWinner(int n, int k) { return josephus(n, k); }

    int josephus(int n, int k)
    {
        if (n == 1)
            return 1;
        return (josephus(n - 1, k) + k - 1) % n + 1;
    }
};