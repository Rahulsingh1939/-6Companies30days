

class Solution
{
public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int> &arr, int k)
    {
        // code here
        priority_queue<pair<int, int>> pq;
        vector<int> result;
        int n = arr.size();

        for (int i = 0; i < k; i++)
        {
            pq.push({arr[i], i});
        }
        result.push_back(pq.top().first);

        for (int i = k; i < n; i++)
        {
            pq.push({arr[i], i});
            while (pq.top().second <= i - k)
            {
                pq.pop();
            }
            result.push_back(pq.top().first);
        }

        return result;
    }
};