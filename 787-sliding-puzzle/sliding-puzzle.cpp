#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  struct BoardHash {
    size_t operator()(const vector<vector<int>> &board) const {
      size_t h = 0;
      for (auto &row : board)
        for (int x : row)
          h = (h << 3) + x;
      return h;
    }
  };
  vector<vector<int>> final = vector<vector<int>>(2, vector<int>(3, 0));
  unordered_map<vector<vector<int>>, bool, BoardHash> vis;
  int slidingPuzzle(vector<vector<int>> &board) {
    // let each board be a state
    // 2 * 3 board
    // 6! states -> 6 * 5 * 24 = 840 states
    // starting at cur state, explore until shortest path to final state
    final[0][0] = 1, final[0][1] = 2, final[0][2] = 3, final[1][0] = 4,
    final[1][1] = 5;
    queue<pair<vector<vector<int>>, int>> q; // board, moves
    q.push({board, 0});
    while (!q.empty()) {
      pair<vector<vector<int>>, int> Pair = q.front();
      q.pop();
      auto cur_board = Pair.first;
      auto moves = Pair.second;
      vis[cur_board] = true;
      if (cur_board == final) {
        return moves;
      }
      for (int r = 0; r < 2; r++) {
        for (int c = 0; c < 3; c++) {
          if (cur_board[r][c] == 0) {
            // up
            if (r == 1) {
              auto board = cur_board;
              swap(board[r][c], board[r - 1][c]);
              if (!vis[board])
                q.push({board, moves + 1});
            }
            // down
            if (r == 0) {
              auto board = cur_board;
              swap(board[r][c], board[r + 1][c]);
              if (!vis[board])
                q.push({board, moves + 1});
            }
            // left
            if (c != 2) {
              auto board = cur_board;
              swap(board[r][c], board[r][c + 1]);
              if (!vis[board])
                q.push({board, moves + 1});
            }
            // right
            if (c != 0) {
              auto board = cur_board;
              swap(board[r][c], board[r][c - 1]);
              if (!vis[board])
                q.push({board, moves + 1});
            }
          }
        }
      }
    }
    return -1;
  }
};