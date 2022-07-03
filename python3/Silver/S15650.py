# dfs && back-tracking
# when get answer, len(temp) == len(answer)
# visited -> unvisited, append -> pop (back tracking)

def dfs(x):
    if len(s) == b:
        print(*s)
        return

    for i in range(x + 1, a + 1):
        visited[i] = True
        s.append(i)
        dfs(i)
        s.pop()
        visited[i] = False


s = []
a, b = map(int, input().split())
arr = [i for i in range(1, a + 1)]
visited = [False] * (a + 1)
dfs(0)
