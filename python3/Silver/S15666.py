# dfs && back-tracking
# when get answer, len(temp) == len(answer)
# visited -> not visit, append -> pop (back tracking)
# duplicate check with, same len -> no add same num

import sys


def dfs(x):
    if len(s) == b:
        print(*s)
        return
    check = 0
    for j in arr:
        if check == j or j < x:
            continue
        s.append(j)
        check = j
        dfs(j)
        s.pop()


s = []
a, b = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))
arr.sort()
dfs(arr[0])
