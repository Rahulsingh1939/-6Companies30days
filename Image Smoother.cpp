class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> res(n, vector<int>(m, 0));
        int dx[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
        int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int sm = img[i][j], s = 1;
                for (int k = 0; k < 8; k++)
                {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (nx >= 0 && ny >= 0 && nx < n && ny < m)
                    {
                        sm += img[nx][ny];
                        s++;
                    }
                }
                res[i][j] = sm / s;
            }
        }
        return res;
    }
};