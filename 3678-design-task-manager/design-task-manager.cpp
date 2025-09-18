#include <bits/stdc++.h>
using namespace std;
class TaskManager {
public:
  set<pair<int, int>> s;                // priority & taskId
  unordered_map<int, pair<int, int>> m; // taskId -> priority, user

  TaskManager(vector<vector<int>> &tasks) {
    // {user, task, priority}
    for (auto t : tasks)
      s.insert({t[2], t[1]}), m[t[1]] = {t[2], t[0]};
  }

  void add(int userId, int taskId, int priority) {
    s.insert({priority, taskId});
    m[taskId] = {priority, userId};
  }

  void edit(int taskId, int newPriority) {
    s.erase({m[taskId].first, taskId});
    s.insert({newPriority, taskId});
    m[taskId].first = newPriority;
  }

  void rmv(int taskId) {
    s.erase({m[taskId].first, taskId});
    m.erase(m.find(taskId));
  }

  int execTop() {
    if (s.empty())
      return -1;
    auto top = *s.rbegin();
    s.erase(top);
    auto userId = m[top.second].second;
    m.erase(top.second);
    return userId;
  }
};