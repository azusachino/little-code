from typing import List


class Solution:
    def numOfMinutes(
        self, n: int, headID: int, manager: List[int], informTime: List[int]
    ) -> int:
        children = [[] for _ in range(n)]
        for i, m in enumerate(manager):
            # not the boss
            if m >= 0:
                children[m].append(i)

        def dfs(i):
            return max([dfs(j) for j in children[i] or [0]]) + informTime[i]

        return dfs(headID)