# dfs && back-tracking
# when get answer, len(temp) == len(answer)
# append -> pop (back tracking)
# check visited with, in

import sys


def dfs(x):
    if len(s) == b:
        print(*s)
        return

    for i in arr:
        if i in s:
            continue
        s.append(i)
        dfs(i)
        s.pop()


s = []
visited = []
a, b = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))
arr.sort()
dfs(arr[0])
