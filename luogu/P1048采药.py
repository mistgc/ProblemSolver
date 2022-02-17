'''
该题是一个01背包问题
'''
if __name__ == '__main__':
    dp = [0 for _ in range(1001)]
    T, M = map(int, input().split())
    for i in range(M):
        v, w = map(int, input().split())
        for j in range(T, v - 1, -1):
                dp[j] = max(dp[j], dp[j - v] + w)
    print(dp[T])
