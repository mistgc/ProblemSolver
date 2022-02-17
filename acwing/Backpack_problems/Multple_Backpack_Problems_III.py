# acwing 中以当前这种方式，用python3会超时
from collections import deque

dp = [0 for _ in range(20010)]
if __name__ == '__main__':
    n, m = map(int, input().split())
    deq = deque()
    for i in range(n):
        v, w, s = map(int, input().split())
        g = dp.copy()
        for j in range(v):
            deq.clear()
            for k in range(j, m+1, v):
                dp[k] = g[k]
                if len(deq) > 0 and deq[0] < k - s * v:
                    deq.popleft()
                if len(deq) > 0:
                    dp[k] = max(dp[k], g[deq[0]] + (k - deq[0]) // v * w)
                while len(deq) > 0 and g[deq[len(deq) - 1]] - (deq[len(deq) - 1] - j) // v * w <= g[k] - (k - j) // v * w:
                    deq.pop()
                deq.append(k)
    
    print(dp[m])
