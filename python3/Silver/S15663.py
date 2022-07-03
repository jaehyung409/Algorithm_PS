# dfs && back-tracking
# when get answer, len(temp) == len(answer)
# visited -> not visit, append -> pop (back tracking)
# duplicate check with, same len -> no add same num

import sys


def dfs():
    if len(s) == b:
        print(*s)
        return
    check = 0
    for j in arr:
        if visited[j[1]] or check == j[0]:
            continue
        s.append(j[0])
        check = j[0]
        visited[j[1]] = True
        dfs()
        visited[j[1]] = False
        s.pop()


s = []
a, b = map(int, sys.stdin.readline().split())
visited = [False] * a
arr = []
arr_t = list(map(int, sys.stdin.readline().split()))
i = 0
for k in arr_t:
    arr.append((k, i))
    i += 1
arr.sort()
dfs()
