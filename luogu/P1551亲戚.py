#!~/AppData/Local/Programs/Python/Python38-32/python.exe
# Disjoint Set
fa = []
rank = []

def init():
    for i in range(5010):
        fa.append(i)
        rank.append(1)

def find(x):
    if fa[x] == x:
        return x
    else:
        return find(fa[x])

def union(x, y):
    i = find(x)
    j = find(y)

    if rank[i] <= rank[j]:
        fa[i] = j
    else:
        fa[j] = i
        
    if rank[i] == rank[j] and i != j:
        rank[j] = rank[j] + 1

n, m, p = map(int, input().split())

init()

for i in range(m):
    x, y = map(int, input().split())
    union(x, y)

for i in range(p):
    x, y = map(int, input().split())
    if find(x) == find(y):
        print('Yes')
    else:
        print('No')
