#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  struct BOARD {
    int n;
    vector<vector<int>> board; // 0 empty, 1 placed, 2 blocked
    BOARD(int n_) : n(n_), board(n_, vector<int>(n_, 0)) {}
    bool fill_row_at(int row, int pos) {
      if (board[row][pos] != 0) {
        return false;
      }
      board[row][pos] = 1;
      for (int spread = 1; spread < n; spread++) {
        int ROW = row + spread;
        if (ROW >= n)
          break;
        int left = pos - spread, right = pos + spread;
        board[ROW][pos] = 2;
        if (left >= 0)
          board[ROW][left] = 2;
        if (right < n)
          board[ROW][right] = 2;
      }
      return true;
    }
    vector<string> convert() {
      vector<string> rep(n, string(n, '.'));
      for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++) {
          rep[r][c] = board[r][c] == 1 ? 'Q' : '.';
        }
      return rep;
    }
  };

  vector<BOARD> answer;

  void solve(BOARD cur_board, int row_to_fill) {
    // default shift
    if (row_to_fill == cur_board.n) {
      answer.push_back(cur_board);
      return;
    }
    for (int pos = 0; pos < cur_board.n; pos++) {
      BOARD board = cur_board;
      if (board.fill_row_at(row_to_fill, pos)) {
        solve(board, row_to_fill + 1);
      }
    }
  }

  vector<vector<string>> convert(vector<BOARD> answer) {
    vector<vector<string>> converted;
    for (auto board : answer) {
      converted.push_back(board.convert());
    }
    return converted;
  }

  vector<vector<string>> solveNQueens(int n) {
    // use BOARD to track boards during backtracking
    answer.clear();
    BOARD board(n);
    solve(board, 0);
    return convert(answer);
  }
};