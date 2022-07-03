# dfs && back-tracking
# when get answer, len(temp) == len(answer)
# append -> pop (back tracking)

def dfs(x):
    if len(s) == b:
        print(*s)
        return

    for i in range(x + 1, a + 1):
        s.append(i)
        dfs(i-1)
        s.pop()


s = []
a, b = map(int, input().split())
arr = [i for i in range(1, a + 1)]
dfs(0)
