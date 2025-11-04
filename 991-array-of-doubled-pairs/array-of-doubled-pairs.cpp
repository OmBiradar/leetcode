class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> count;
        for (int x : arr) count[x]++;
        
        vector<int> keys;
        keys.reserve(count.size());
        for (auto& [k, _] : count) keys.push_back(k);
        sort(keys.begin(), keys.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });
        
        for (int x : keys) {
            if (count[x] > count[2 * x])
                return false;
            count[2 * x] -= count[x];
        }
        return true;
    }
};
