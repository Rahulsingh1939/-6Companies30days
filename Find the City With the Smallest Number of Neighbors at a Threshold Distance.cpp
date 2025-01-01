class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distThreshold)
    {
        vector<vector<int>> dist(n, vector<int>(n, 1e9)); // Initialize dist matrix with infinity

        for (int i = 0; i < n; ++i)
        {
            dist[i][i] = 0; // dist to itself is 0
        }

        for (auto &edge : edges)
        {
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }

        // Floyd-Warshall algorithm to find all-pairs shortest path
        for (int k = 0; k < n; ++k)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    dist[i][j] =
                        min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int ans = -1;
        int mn = INT_MAX;
        for (int i = 0; i < n; ++i)
        {
            int cnt = 0;
            for (int j = 0; j < n; ++j)
            {
                if (i != j && dist[i][j] <= distThreshold)
                {
                    ++cnt;
                }
            }
            if (cnt <= mn)
            {
                mn = cnt;
                ans = i;
            }
        }

        return ans;
    }
};