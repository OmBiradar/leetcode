class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1;
        if (target == "0000") return 0;

        queue<pair<string, int>> q;
        unordered_set<string> vis;
        q.push({"0000", 0});
        vis.insert("0000");

        while (!q.empty()) {
            auto [s, d] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                for (int move : {-1, 1}) {
                    string next = s;
                    next[i] = (s[i] - '0' + move + 10) % 10 + '0';
                    if (!dead.count(next) && !vis.count(next)) {
                        if (next == target) return d + 1;
                        vis.insert(next);
                        q.push({next, d + 1});
                    }
                }
            }
        }

        return -1;
    }
};
