class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        cnt = 0
        m, n = len(grid), len(grid[0])
        vis = [[0] * n for _ in range(m)]
        def dfs(x, y):
            if x < 0 or y < 0 or x >= m or y >= n:
                return
            if grid[x][y] == '0':
                return
            if vis[x][y]:
                return
            vis[x][y] = 1
            dfs(x + 1, y), dfs(x - 1, y)
            dfs(x, y + 1), dfs(x, y - 1)
        for i in range(m):
            for j in range(n):
                if vis[i][j]:
                    continue;
                if grid[i][j] == '1':
                    cnt = cnt + 1
                    dfs(i, j)
        return cnt