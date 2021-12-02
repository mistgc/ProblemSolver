f = []
n, m = map(int, input().split())
# Initialize f to be 0.
for i in range(m + 1):
    f.append(0)
for i in range(n):
    v, w, s = map(int, input().split())
    for j in reversed(range(m + 1)):
        for k in range(s + 1):
            if k * v > j:
                break
            f[j] = max(f[j], f[j - k * v] + k * w)
print(f[m])
