class Solution
{
#define all(x) x.begin(), x.end()
public:
    vector<bool> subsequenceSumAfterCapping(vector<int> &arr, int k)
    {
        int n = arr.size();
        sort(all(arr));
        vector<bool> sum(k + 1, 0), ans(n, 0);
        sum[0] = 1;

        // sum[i] = can we form sum i using elements < x
        // ans[i] = can we form sum k using all elements with each element capped at i
        for (int i = 0, x = 1; x <= n; x++)
        {
            while (i < n && arr[i] < x)
            {
                // classic knapsack to find all sums possible using elements < x
                for (int j = k; j >= arr[i]; j--)
                    if (sum[j - arr[i]])
                        sum[j] = 1;
                i++;
            }

            int bigger = n - i; // count of elements >= x
            // try to form all multiples of x till k using elements >= x
            for (int j = 0; j <= bigger && j * x <= k; j++)
            {
                if (sum[k - j * x]) // can we form the remainder using elements < x
                {
                    ans[x - 1] = 1;
                    break;
                }
            }
        }
        return ans;
    }
};